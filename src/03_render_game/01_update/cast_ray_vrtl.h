/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vrtl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:59:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:31:56 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_VRTL_H
# define CAST_RAY_VRTL_H

# include "cub3d.h"

void	get_vrtl_intersection_east(t_ray *ray, t_map *map, t_player *player);
void	get_vrtl_intersection_west(t_ray *ray, t_map *map, t_player *player);

#endif
