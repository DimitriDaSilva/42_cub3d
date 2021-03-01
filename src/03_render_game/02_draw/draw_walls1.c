/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:43:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 16:37:54 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls.h"

/*
** Draws the walls one column at a time
** @param:	- [t_game *] root struct
** Line-by-line comments:
** @11		No need to get width as it is 1 pixel
*/

void		draw_walls(t_game *game)
{
	int		i;
	double	wall_height;
	t_rect	rect;
	t_ray	*ray;

	i = -1;
	while (++i < game->scene.res.width)
	{
		ray = &game->rays.arr[i];
		wall_height = get_wall_height(game, ray);
		rect.x = i;
		rect.y = get_y_wall_position(game, wall_height);
		rect.height = wall_height;
		rect.tex = get_wall_texture(&game->scene, ray->orientation);
		draw_wall_strip(&rect, game->mlx.img.data, &game->scene.res, ray);
	}
}

/*
** Gets wall height
** @param:	- [t_game *] root struct
**			- [t_ray *] ray struct that gives us the angle and the grid
**                      distance between player and wall
** @return:	[double] wall height
** Line-by-line comments:
** @5		Euclidian implementation of the raycasting suffers from inherent
**			fisheye effect. This fixes it
** @6		Goes from grid distance to full scale distance
*/

double		get_wall_height(t_game *game, t_ray *ray)
{
	double	wall_height;
	double	scaled_distance;
	double	fisheye_adjustment;

	fisheye_adjustment = cos(ray->angle - game->player.rotation_angle);
	scaled_distance = ray->size * SCALE * fisheye_adjustment;
	wall_height = (SCALE / (scaled_distance)) * game->rays.dist_proj_plane;
	return (wall_height);
}

/*
** Gets the vertical position of the beginning of the wall
** @param:	- [t_game *] root struct
**			- [double] wall height
** @return:	[int] y coordinate
** Line-by-line comments:
** @5		I go to the horizontal center of the screen
** @6-7		As I know the wall will be horizontally centered, I just need to
**			add half the height of the wall to find where it should begin
** @8-9		Edge case: I'm so close to the wall that it's height is higher
**			than screen height then it begin draw at the top of the screen
*/

int			get_y_wall_position(t_game *game, double wall_height)
{
	double	center_screen;
	double	center_wall;
	int		y;

	center_screen = game->scene.res.height / 2;
	center_wall = wall_height / 2;
	y = center_screen - center_wall;
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
