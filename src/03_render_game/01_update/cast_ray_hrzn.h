/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_hrzn.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:59:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/04 19:00:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_HRZN_H
# define CAST_RAY_HRZN_H

# include "cub3d.h"

void	get_hrzn_intersection_SE(t_ray *ray, t_map *map, t_player *player);
void	get_hrzn_intersection_SW(t_ray *ray, t_map *map, t_player *player);
void	get_hrzn_intersection_NW(t_ray *ray, t_map *map, t_player *player);
void	get_hrzn_intersection_NE(t_ray *ray, t_map *map, t_player *player);

#endif
