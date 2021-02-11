/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_player.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:09:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/11 00:09:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_PLAYER_H
# define READY_GAME_PLAYER_H

# include "cub3d.h"

void		get_starting_position(t_player *player, char **grid);
double		get_starting_orientation(char orientation);

#endif
