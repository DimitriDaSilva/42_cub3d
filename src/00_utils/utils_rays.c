/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:29:42 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 20:19:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_rays.h"

/*
** Each time a grid intersection (x == 0 or y == 0) is found, this function
** checks if it's a wall
** @param:	- [t_map *] map struct with grid, width and height
**			- [double] x position of the ray being casted
**			- [double] y position of the ray being casted
**			- [t_ray *] struct of current ray
** @return:	[int] 1 for true and 0 for false
** Line-by-line comments:
** @1-2		Updating the position of the ray
**			Can be improved on changing these value on the function caller
** @3-7		Edge case: the ray went out of the bounds of the grid. We stop	
**			the ray and give it a value really high so that he doesn't get
**			picked as the closest to the player
** @8-13	Edge case: the ray ended up right on the south border of the grid.
**			As the grid is a NULL terminated array of strings, if check a x
**			value of that line we do seg fault
*/

int	is_wall(t_map *map, double x, double y, t_ray *ray)
{
	ray->x = x;
	ray->y = y;
	if ((int)x < 0 || map->width < (int)x || (int)y < 0 || map->height < (int)y)
	{
		ray->size = INT_MAX;
		return (1);
	}
	if (map->height == (int)y)
	{	
		ray->obstacle = '1';
		ray->orientation = 'N';
		return (1);
	}
	ray->obstacle = map->grid[(int)y][(int)x];
	if (ray->obstacle == '1')
	{
		ray->orientation = get_wall_orientation(map, (int)x, (int)y, ray);
		return (1);
	}
	return (0);
}

/*
** Gets the orientation of a wall. If we found this wall it means there is
** at least one non-wall space next to it. We also take into account which
** grid border (hrzn or vrtl) was touched and the angle of the ray touching
** the wall 
** @param:	- [t_map *] map struct with grid, width and height
**			- [int] x position of the ray being casted
**			- [int] y position of the ray being casted
**			- [t_ray *] struct of current ray
** @return:	[char] N S E or W
** Line-by-line comments:
** @1-8		Edge cases: wall on the edges of the grid need to be taken into
**			account separately to avoid seg fault
*/

char	get_wall_orientation(t_map *map, int x, int y, t_ray *ray)
{
	if (x == 0)
		return ('E');
	else if (x == map->width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->height - 1)
		return ('N');
	if (ray->side == 'H')
	{
		if (map->grid[y - 1][x] != '1' && is_south(ray->angle))
			return ('N');
		else if (map->grid[y + 1][x] != '1' && !is_south(ray->angle))
			return ('S');
	}
	else
	{
		if (map->grid[y][x - 1] != '1' && !is_west(ray->angle))
			return ('W');
		else if (map->grid[y][x + 1] != '1' && is_west(ray->angle))
			return ('E');
	}
	return (0);
}

int	is_south(double angle)
{
	if (0 <= angle && angle < M_PI)
		return (1);
	else
		return (0);
}

int	is_west(double angle)
{
	if (M_PI / 2 <= angle && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}
