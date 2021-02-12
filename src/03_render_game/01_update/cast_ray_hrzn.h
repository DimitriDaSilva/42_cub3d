/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_hrzn.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:59:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 20:18:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_HRZN_H
# define CAST_RAY_HRZN_H

# include "cub3d.h"

void	get_hrzn_intersection_south(t_ray *ray, t_map *map, t_player *player);
void	get_hrzn_intersection_north(t_ray *ray, t_map *map, t_player *player);

#endif
