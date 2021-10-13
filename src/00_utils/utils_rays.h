/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:30:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:29:49 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RAYS_H
# define UTILS_RAYS_H

# include "cub3d.h"

int		is_wall(t_map *map, double x, double y, t_ray *ray);
char	get_wall_orientation(t_map *map, int x, int y, t_ray *ray);
int		is_south(double angle);
int		is_west(double angle);

#endif
