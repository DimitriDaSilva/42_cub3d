/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event_hooks.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:42:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 21:46:15 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_EVENT_HOOKS_H
# define SET_EVENT_HOOKS_H

# include "cub3d.h"

int		key_pressed(int keycode, t_game *game);
void	update_player_position(t_player *player, char **grid, int keycode);
void	update_player_orientation(t_player *player, int keycode);
int		key_released(int keycode, t_game *game);
int		close_window_cross(int keycode, t_game *game);

#endif
