/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:18:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 11:34:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SPRITES_H
# define DRAW_SPRITES_H

# include "cub3d.h"

void	draw_single_sprite(t_game *game, t_sprite *sprite);
double	get_sprite_height(t_game *game, double distance);
int		get_y_sprite_position(t_game *game, double sprite_height);
int		get_x_sprite_position(t_game *game, t_sprite *sprite, double sprite_width);
// void	draw_sprite_strip(t_rect *rect, t_sprite *sprite, t_game *game, int x_tex);
void	draw_sprite_strip(t_rect *rect, t_sprite *sprite, t_game *game, int x_tex, int x1);

#endif
