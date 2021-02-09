/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:29:42 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/08 15:38:16 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_rays1.h"

int		check_orientation(t_ray *ray, double deg_low, double deg_high)
{
	double	rad_low;
	double	rad_high;

	rad_low = deg_to_rad(deg_low);
	rad_high = deg_to_rad(deg_high);
	if (rad_low <= ray->angle && ray->angle < rad_high)
		return (1);
	else
		return (0);
}

int		is_obstacle(t_map *map, double x, double y, t_ray *ray)
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
		ray->orientation = get_orientation(map, (int)x, (int)y, ray);
		return (1);
	}
	else if (ray->obstacle == '2')
		add_sprite(ray, x, y, ray->obstacle);
	return (0);
}

char	get_orientation(t_map *map, int x, int y, t_ray *ray)
{
	if (x == 0)
		return ('E');
	else if (x == map->width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->height - 1)
		return ('N');
	if (map->grid[y - 1][x] != '1' && ray->side == 'H' && is_looking_south(ray->angle))
		return ('N');
	else if (map->grid[y + 1][x] != '1' && ray->side == 'H' && !is_looking_south(ray->angle))
		return ('S');
	else if (map->grid[y][x - 1] != '1' && ray->side == 'V' && !is_looking_west(ray->angle))
		return ('W');
	else if (map->grid[y][x + 1] != '1' && ray->side == 'V' && is_looking_west(ray->angle))
		return ('E');
	return 0;
}

int		is_looking_south(double angle)
{
	if (0 <= angle && angle < M_PI)
		return (1);
	else
		return (0);
}

int		is_looking_west(double angle)
{
	if (M_PI / 2 <= angle && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}
