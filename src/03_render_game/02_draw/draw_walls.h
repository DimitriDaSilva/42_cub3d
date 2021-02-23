/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:42:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:31:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WALLS_H
# define DRAW_WALLS_H

# include "cub3d.h"

/*
** draw_walls1
*/

double		get_wall_height(t_game *game, t_ray *ray);
int			get_y_wall_position(t_game *game, double wall_height);
t_texture	get_wall_texture(t_scene *scene, char orientation);

/*
** draw_walls2
*/

void		draw_wall_strip(t_rect *rect, int *img, t_res *res, t_ray *ray);
int			get_bitmap_offset(t_ray *ray, int bitmap_width);

#endif
