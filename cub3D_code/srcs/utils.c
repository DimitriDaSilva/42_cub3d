/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:43:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/04 19:47:17 by dda-silv         ###   ########.fr       */
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
		return (1);
	ray->obstacle = map->grid[y_int][x_int];
	if (ft_strchr("12", ray->obstacle))
		return (1);
	else
		return (0);
}

int		check_orientation(double radian, double deg_low, double deg_high)
{
	if (deg_to_rad(deg_low) <= normalize_radian(radian) &&
		normalize_radian(radian) < deg_to_rad(deg_high))
		return (1);
	else
		return (0);
}

double	normalize_radian(double radian)
{
	double	full_circle;

	full_circle = deg_to_rad(360);
	radian = ft_remainder(radian, full_circle);
	if (radian <= 0)
		radian += full_circle;
	return (radian);
}
