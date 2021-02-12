/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:43:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 12:00:35 by dda-silv         ###   ########.fr       */
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
		rect.tex = get_wall_texture(&game->scene,
				game->rays.arr[i].orientation);
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

int	get_y_wall_position(t_game *game, double wall_height)
{
	double	center_screen;
	int		y;

	center_screen = game->scene.res.height / 2;
	y = center_screen - wall_height / 2;
	if (y < 0)
		y = 0;
	return (y);
}

t_texture	get_wall_texture(t_scene *scene, char orientation)
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
