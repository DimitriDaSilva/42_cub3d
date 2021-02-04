/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:43:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/04 00:05:19 by dda-silv         ###   ########.fr       */
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

int		is_obstacle(char **grid, double x, double y)
{
	char	grid_item;

	if (ft_remainder(x, 1) == 0)
		x--;
	if (ft_remainder(y, 1) == 0)
		y--;

	if (grid[(int)y] == 0)
		return (1);
	grid_item = grid[(int)y][(int)x];
	if (grid_item == 0)
		return (1);
	else if (ft_strchr("12", grid_item))
		return (1);
	else
		return (0);
}
