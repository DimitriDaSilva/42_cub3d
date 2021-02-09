/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:18:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/08 20:27:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_sprites.h"

void	draw_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	curr;

	i = -1;
	while (++i < game->scene.res.width)
	{
		if (game->rays.arr[i].total_sprites == 0)
			continue ;
		adjust_sprite_pos(&game->rays.arr[i]);
		get_sprite_distances(&game->rays.arr[i], &game->player);
		sort_sprites(&game->rays.arr[i]);
		j = -1;
		while (++j < game->rays.arr[i].total_sprites)
		{
			curr = game->rays.arr[i].sprites[j];
			if (curr.distance < game->rays.arr[i].size)
				draw_sprite(game, &game->rays.arr[i].sprites[j], i);
		}
		free(game->rays.arr[i].sprites);
	}
}

void	adjust_sprite_pos(t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < ray->total_sprites)
	{
		ray->sprites[i].x = floor(ray->sprites[i].x) + 0.5;
		ray->sprites[i].y = floor(ray->sprites[i].y) + 0.5;
	}
}

void	get_sprite_distances(t_ray *ray, t_player *player)
{
	int	dx;
	int	dy;
	int	i;

	i = -1;
	while (++i < ray->total_sprites)
	{
		dx = pow(player->x - ray->sprites[i].x, 2); 
		dy = pow(player->y - ray->sprites[i].y, 2); 
		ray->sprites[i].distance = sqrt(dx + dy);
	}
}

void	sort_sprites(t_ray *ray)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < ray->total_sprites)
	{
		j = -1;
		while (++j < ray->total_sprites - 1)
		{
			if (ray->sprites[j].distance < ray->sprites[j + 1].distance)
			{
				tmp = ray->sprites[j];
				ray->sprites[j] = ray->sprites[j + 1];
				ray->sprites[j + 1] = tmp;
			}
		}
	}
}

void	draw_sprite(t_game *game, t_sprite *sprite, int posX;)
{
	double	sprite_height;
	t_rect	rect;

	sprite_height = get_sprite_height(game, sprite->distance);
	rect.x = posX;
	rect.y = get_y_sprite_position(game, sprite_height);
	rect.height = sprite_height;
	rect.tex = get_sprite_texture(&game->scene, sprite->item);
	draw_sprite_strip(&rect,
					game->mlx.img.data,
					&game->scene.res,
					sprite);
}

double	get_sprite_height(t_game *game, double distance)
{
	double	sprite_height;
	double	scaled_distance;

	scaled_distance = distance * SCALE;
	sprite_height = (SCALE / (scaled_distance)) * game->rays.dist_proj_plane;
	return (sprite_height);
}

int		get_y_sprite_position(t_game *game, double sprite_height)
{
	double	center_screen;
	int		y;
	
	center_screen = game->scene.res.height / 2;
	y = center_screen - sprite_height / 2;
	if (y < 0)
		y = 0;
	return (y);
}

t_texture	get_sprite_texture(t_scene *scene, char item)
{
	// if (item == '2')
	return (scene->sprite_tex);
}

void	draw_sprite_strip(t_rect *rect, int *img, t_res *res, t_sprite *sprite)
{
	int	y;
	int	y_tex;
	int	x_tex;
	int	color;
	double	step;
	double	texPos;

	step = 1.0 * rect->tex.height / rect->height;
	texPos = (rect->y - res->height / 2 + rect->height / 2) * step;
	x_tex = get_bitmap_offset_stripe(ray, rect->tex.width);
	y = -1;
	while (++y < rect->height && y < res->height)
	{
		y_tex = (int)texPos & (rect->tex.height - 1);
		texPos += step;
		color = rect->tex.img.data[y_tex * rect->tex.height + x_tex];
		img[(rect->y + y) * res->width + rect->x] = color;
	}
}

int		get_bitmap_offset_stripe(t_ray *ray, int bitmap_width)
{
	double	remainder;
	int	offset;

	if (ray->side == 'H')
	{
		remainder = ray->x - floor(ray->x);
		offset = floor(bitmap_width * remainder);
	}
	else
	{
		remainder = ray->y - floor(ray->y);
		offset = floor(bitmap_width * remainder);
	}
	return (offset);
}
