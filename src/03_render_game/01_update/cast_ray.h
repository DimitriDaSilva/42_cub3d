/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:33:18 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:31:50 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_H
# define CAST_RAY_H

# include "cub3d.h"

void	get_hrzn_intersection(t_ray *ray, t_map *map, t_player *player);
void	get_vrtl_intersection(t_ray *ray, t_map *map, t_player *player);

#endif
