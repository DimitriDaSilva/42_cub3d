/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:47:53 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/09 20:49:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_SPRITES_H
# define UPDATE_SPRITES_H

# include "cub3d.h"

void	update_sprite_angle(t_game *game, t_sprite *sprite);
void	update_sprite_visibility(t_game *game, t_sprite *sprite);
void	update_sprite_distance(t_game *game, t_sprite *sprite);
void	update_sprites_order(t_game *game, t_sprite *sprites);

#endif
