/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vrtl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:59:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/04 19:03:56 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_VRTL_H
# define CAST_RAY_VRTL_H

# include "cub3d.h"

void	get_vrtl_intersection_SE(t_ray *ray, t_map *map, t_player *player);
void	get_vrtl_intersection_SW(t_ray *ray, t_map *map, t_player *player);
void	get_vrtl_intersection_NW(t_ray *ray, t_map *map, t_player *player);
void	get_vrtl_intersection_NE(t_ray *ray, t_map *map, t_player *player);

#endif
