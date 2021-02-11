/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:18:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 15:38:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_sprites.h"

void	draw_sprites(t_game *game)
{
	int			i;
	t_sprite	*sprite;

	i = -1;
	while (++i < game->scene.total_sprites)
	{
		sprite = &game->scene.sprites[i];
		if (sprite->is_visible)
			draw_single_sprite(game, &game->scene.sprites[i]);
	}
}

void	draw_single_sprite(t_game *game, t_sprite *sprite)
{
	t_rect	rect;
	double	column_width;
	int		i;
	int		j;
	int		posX;

	rect.height = get_sprite_height(game, sprite->distance);
	rect.y = get_y_sprite_position(game, rect.height);
	rect.x = get_x_sprite_position(game, sprite, rect.height);
	column_width = rect.height / sprite->tex->height;
	i = -1;
	while (++i < sprite->tex->width)
	{
		j = -1;
		while (++j < column_width)
		{
			posX = (int)(rect.x + (i - 1) * column_width + j);
			if (posX >= 0 && posX <= game->scene.res.width - 1
				&& sprite->distance < game->rays.arr[posX].size)
				draw_sprite_strip(&rect, sprite, game, i, posX);
		}
	}
}

double	get_sprite_height(t_game *game, double distance)
{
	double	scaled_distance;
	double	sprite_height;

	scaled_distance = distance * SCALE;
	sprite_height = (SCALE / scaled_distance) * game->rays.dist_proj_plane;
	return (sprite_height);
}

int		get_y_sprite_position(t_game *game, double sprite_height)
{
	int	center_screen;
	int	center_sprite;
	int	y;
	
	center_screen = game->scene.res.height / 2;
	center_sprite = sprite_height / 2;
	y = center_screen - center_sprite;
	if (y < 0)
		y = 0;
	return (y);
}

int		get_x_sprite_position(t_game *game, t_sprite *sprite, double sprite_width)
{
	double	center_sprite;
	int		center_screen;
	double	begin_sprite;

	center_sprite = tan(sprite->rotation_angle) * game->rays.dist_proj_plane;
	center_screen = game->scene.res.width / 2;
	begin_sprite = center_screen + center_sprite - sprite_width / 2;
	return (begin_sprite);
}


void	draw_sprite_strip(t_rect *rect, t_sprite *sprite, t_game *game, int x_tex, int x1)
{
	double	step;
	double	texPos;
	int		y;
	int		y_tex;
	int		color;

	step = 1.0 * sprite->tex->height / rect->height;
	texPos = (rect->y - game->scene.res.height / 2 + rect->height / 2) * step;
	y = -1;
	while (++y < rect->height && y < game->scene.res.height)
	{
		y_tex = (int)texPos & (sprite->tex->height - 1);
		texPos += step;
		color = sprite->tex->img.data[y_tex * sprite->tex->height + x_tex];
		if (color < 0)
			continue ;
		game->mlx.img.data[(rect->y + y) * game->scene.res.width + x1] = color;
	}
}

// void	draw_sprite(t_rect *rect, t_sprite *sprite, int *img, t_res *res)
// {
// 	int		column_width;
// 	int		i;
// 	int		j;
// 	int		posX;

// 	column_width = sprite_height / sprite->tex.height;
// 	i = -1;
// 	while (++i < sprite->tex.width)
// 	{
// 		j = -1;
// 		while (++j < column_width)
// 		{
// 			posX = (int)(rect->x + ((i - 1) * column_width) + j);
// 			if (sprite->distance < game->rays.arr[posX].size)
// 				draw_sprite_strip(rect, sprite, img, res);
// 		}
// 	}
// }
