/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:32:24 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/04 00:01:15 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray.h"

void	cast_ray(t_ray *ray, char **grid, t_player *player)
{
	(void)ray;
	t_ray	hrzn_inter;
	// t_ray	vert_inter;

	get_hrzn_intersections(&hrzn_inter, grid, player);
}

/*
** On a grid, checks all horizontal intersections of the ray casted and stores
** its size and the obstacle it hit
** @param:	- [t_ray *] ray (double distance and char obstacle)
**			- [char **] map formatted in a 2d array of chars
**			- [t_player *] player to get its position in the grid
** Line-by-line comments:
** @9		Here distance_to_next_line is the opposite
*/

void	get_hrzn_intersections(t_ray *ray, char **grid, t_player *player)
{
	double	x;
	double	y;
	double	distance_to_next_line;
	double	adjacent;

	x = player->x;
	y = player->y;
	ray->size = 0;
	// player->rotation_angle = deg_to_rad(85);
	distance_to_next_line = (y - (int)y) * (-1);
	while (!is_obstacle(grid, x, y))
	{
		y += distance_to_next_line;
		adjacent = distance_to_next_line / tan(player->rotation_angle);
		x += adjacent;
		ray->size += sqrt(pow(adjacent, 2) + pow(distance_to_next_line, 2));
		distance_to_next_line = -1;
	}
	ray->obstacle = grid[(int)y][(int)x];
}
