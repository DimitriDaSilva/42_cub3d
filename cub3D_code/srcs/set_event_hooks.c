/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:40:31 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 21:48:10 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_event_hooks.h"

void	set_event_hooks(t_game *game)
{
	mlx_hook(game->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_pressed, game);
	mlx_hook(game->mlx.win, KEY_RELEASE, KEY_RELEASE_MASK, key_released, game);
	mlx_hook(game->mlx.win, CLIENT_MESSAGE, NO_MASK, close_window_cross, game);
}

int		key_pressed(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_Z || keycode == KEY_S)
		update_player_position(&game->player, game->scene.map.grid, keycode);
	else if (keycode == KEY_Q || keycode == KEY_D)
		update_player_orientation(&game->player, keycode);
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

void	update_player_position(t_player *player, char **grid, int keycode)
{
	double	move_step;
	double	tmp_x;
	double	tmp_y;

	tmp_x = player->x;
	tmp_y = player->y;
	if (keycode == KEY_Z)
		player->walk_direction = 1;
	else if (keycode == KEY_S)
		player->walk_direction = -1;
	move_step = player->walk_direction * player->move_speed;
	tmp_x += cos(player->rotation_angle) * move_step;
	tmp_y += sin(player->rotation_angle) * move_step;
	if (grid[(int)tmp_y][(int)tmp_x] == '0')
	{
		player->x = tmp_x;
		player->y = tmp_y;
	}
}

void	update_player_orientation(t_player *player, int keycode)
{
	double	rotation;

	if (keycode == KEY_Q)
		player->turn_direction = -1;
	else if (keycode == KEY_D)
		player->turn_direction = 1;
	rotation = player->turn_direction * player->rotation_speed;
	player->rotation_angle += rotation;
}

int		key_released(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_Z)
		game->player.walk_direction = 0;
	else if (keycode == KEY_S)
		game->player.walk_direction = 0;
	else if (keycode == KEY_Q)
		game->player.turn_direction = 0;
	else if (keycode == KEY_D)
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