/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:43:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/06 11:02:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	unload_strs(char **strs)
{
	while (*strs)
		free(*strs++);
}

double	rad_to_deg(double rad)
{
	return (rad * 180.0 / M_PI);
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

int		is_obstacle(t_map *map, double x, double y, t_ray *ray)
{
	int	x_int;
	int	y_int;

	x_int = (int)x;
	y_int = (int)y;
	if (x_int < 0 || map->width < x_int || y_int < 0 || map->height < y_int)
	{
		ray->size = INT_MAX;
		return (1);
	}
	if (x_int == 0 || map->width == x_int || y_int == 0 || map->height == y_int)
	{	
		ray->obstacle = '1';
		return (1);
	}
	ray->obstacle = map->grid[y_int][x_int];
	if (ft_strchr("12", ray->obstacle))
	{
		ray->orientation = get_orientation(map, x_int, y_int, rad_to_deg(ray->angle));
		return (1);
	}
	else
		return (0);
}

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

char	get_orientation(t_map *map, int x, int y, double angle)
{
	(void)map;
	(void)x;
	(void)y;

	if (315 <= angle || angle < 45)
		return ('E');
	else if (45 <= angle && angle < 135)
		return ('S');
	else if (135 <= angle && angle < 225)
		return ('W');
	else if (225 <= angle && angle < 315)
		return ('N');
	return 0;
}
