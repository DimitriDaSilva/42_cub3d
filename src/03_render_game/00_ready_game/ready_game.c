/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:28:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:32:05 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ready_game.h"

void	ready_game(t_game *game)
{
	ready_game_player(game);
	ready_game_sprites(game);
	ready_game_events(game);
	ready_game_others(game);
}
