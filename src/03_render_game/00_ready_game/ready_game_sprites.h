/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_sprites.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:07:54 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/11 00:08:17 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_SPRITES_H
# define READY_GAME_SPRITES_H

# include "cub3d.h"

void		get_map_items(t_scene *scene, t_map *map);
void		add_sprite(t_scene *scene, int x, int y, char sprite);
t_texture	*get_sprite_tex(t_scene *scene, char sprite);

#endif
