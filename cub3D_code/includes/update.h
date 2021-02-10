/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:21:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/09 20:06:38 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "cub3d.h"
# include "update_sprites.h"

void	update_player_position(t_player *player, char **grid);
void	update_player_orientation(t_player *player);
void	update_rays(t_game *game);
void	cast_ray(t_ray *ray, t_map *map, t_player *player);
void	update_sprites(t_game *game);

#endif
