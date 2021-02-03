/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:40:31 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/03 11:50:58 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_event_hooks.h"

void	set_event_hooks(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx.mlx_ptr);
	mlx_hook(game->mlx.win, KeyPress, KeyPressMask, key_pressed, game);
	mlx_hook(game->mlx.win, KeyRelease, KeyReleaseMask, key_released, game);
	mlx_hook(game->mlx.win, ClientMessage, NoEventMask, close_window_cross, game);
}

int		key_pressed(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->player.walk_direction = 'w';
	else if (keycode == K_A)
		game->player.walk_direction = 'a';
	else if (keycode == K_S)
		game->player.walk_direction = 's';
	else if (keycode == K_D)
		game->player.walk_direction = 'd';
	else if (keycode == K_LEFT_ARROW)
		game->player.turn_direction = -1;
	else if (keycode == K_RIGHT_ARROW)
		game->player.turn_direction = 1;
	else if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int		key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		game->player.walk_direction = 0;
	else if (keycode == K_LEFT_ARROW || keycode == K_RIGHT_ARROW)
		game->player.turn_direction = 0;
	return (1);
}

int		close_window_cross(int keycode, t_game *game)
{
	(void)game;
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (1);
}