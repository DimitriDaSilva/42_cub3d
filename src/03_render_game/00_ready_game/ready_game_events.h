/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_events.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:06:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:38:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_EVENTS_H
# define READY_GAME_EVENTS_H

# include "cub3d.h"

int	key_pressed(int keycode, t_game *game);
int	key_released(int keycode, t_game *game);
int	close_window_cross(int keycode, t_game *game);

#endif
