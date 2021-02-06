/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:44:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/06 10:58:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

void	unload_strs(char **strs);
double	rad_to_deg(double rad);
double	deg_to_rad(double deg);
int		is_obstacle(t_map *map, double x, double y, t_ray *ray);
int		check_orientation(t_ray *ray, double deg_low, double deg_high);
char	get_orientation(t_map *map, int x, int y, double angle);

#endif
