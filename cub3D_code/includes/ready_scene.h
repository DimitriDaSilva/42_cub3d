/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_scene.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:28:39 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 11:15:32 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_SCENE_H
# define READY_SCENE_H

# include "cub3d.h"

void		init_player(t_scene *scene, t_player *player);
void		get_starting_position(t_player *player, char **grid);
double		get_starting_orientation(char orientation);
void		get_map_items(t_scene *scene, t_map *map);
void		add_sprite(t_scene *scene, int x, int y, char sprite);
t_texture	*get_sprite_tex(t_scene *scene, char sprite);

#endif
