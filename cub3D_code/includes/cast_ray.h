/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:33:18 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/04 19:04:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_H
# define CAST_RAY_H

# include "cub3d.h"

void	get_hrzn_intersection(t_ray *ray, t_map *map, t_player *player);
void	get_vrtl_intersection(t_ray *ray, t_map *map, t_player *player);

#endif
