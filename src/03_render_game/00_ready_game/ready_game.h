/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:28:39 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:32:03 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_H
# define READY_GAME_H

# include "cub3d.h"

void	ready_game_player(t_game *game);
void	ready_game_sprites(t_game *game);
void	ready_game_events(t_game *game);
void	ready_game_others(t_game *game);

#endif
