/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:06:26 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/08 17:06:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RAYS2_H
# define UTILS_RAYS2_H

# include "cub3d.h"

double	normalize_radian(double radian);
void	add_sprite(t_ray *ray, double x, double y, char sprite);
void	merge_sprites(t_ray *ray, t_ray *tmp);

#endif
