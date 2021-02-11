/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:28:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/11 00:00:30 by dda-silv         ###   ########.fr       */
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
