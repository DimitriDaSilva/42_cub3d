/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:43:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/09 09:40:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls.h"

void	draw_walls(t_game *game)
{
	int		i;
	double	wall_height;
	t_rect	rect;

	i = -1;
	while (++i < game->scene.res.width)
	{
		wall_height = get_wall_height(game, &game->rays.arr[i]);
		rect.x = i;
		rect.y = get_y_wall_position(game, wall_height);
		rect.height = wall_height;
		rect.tex = get_texture(&game->scene, game->rays.arr[i].orientation);
		draw_wall_strip(&rect,
						game->mlx.img.data,
						&game->scene.res,
						&game->rays.arr[i]);
	}
}

double	get_wall_height(t_game *game, t_ray *ray)
{
	double	wall_height;
	double	scaled_distance;
	double	fisheye_adjustment;

	fisheye_adjustment = cos(ray->angle - game->player.rotation_angle);
	scaled_distance = ray->size * SCALE * fisheye_adjustment;
	wall_height = (SCALE / (scaled_distance)) * game->rays.dist_proj_plane;
	return (wall_height);
}

int		get_y_wall_position(t_game *game, double wall_height)
{
	double	center_screen;
	int		y;
	
	center_screen = game->scene.res.height / 2;
	y = center_screen - wall_height / 2;
	if (y < 0)
		y = 0;
	return (y);
}

t_texture	get_texture(t_scene *scene, char orientation)
{
	if (orientation == 'N')
		return (scene->no_tex);
	else if (orientation == 'S')
		return (scene->so_tex);
	else if (orientation == 'E')
		return (scene->ea_tex);
	else
		return (scene->we_tex);
}

void	draw_wall_strip(t_rect *rect, int *img, t_res *res, t_ray *ray)
{
	int	y;
	int	y_tex;
	int	x_tex;
	int	color;
	double	step;
	double	texPos;

	step = 1.0 * rect->tex.height / rect->height;
	texPos = (rect->y - res->height / 2 + rect->height / 2) * step;
	y = -1;
	x_tex = get_bitmap_offset(ray, rect->tex.width);
	while (++y < rect->height && y < res->height)
	{
		y_tex = (int)texPos & (rect->tex.height - 1);
		texPos += step;
		color = rect->tex.img.data[y_tex * rect->tex.height + x_tex];
		img[(rect->y + y) * res->width + rect->x] = color;
	}
}

int		get_bitmap_offset(t_ray *ray, int bitmap_width)
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
