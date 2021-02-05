/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:42:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/05 18:51:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WALLS_H
# define DRAW_WALLS_H

# include "cub3d.h"

double	get_wall_height(t_game *game, t_ray *ray);
int		get_y_wall_position(t_game *game, double wall_height);

#endif
