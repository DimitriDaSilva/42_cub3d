/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:18:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/03 11: 6:11by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

void	update(t_game *game)
{
	update_player_position(&game->player, game->scene.map.grid);
	update_player_orientation(&game->player);
}

void	update_player_position(t_player *player, char **grid)
{
	double	move_step;
	double	rotation;

	if (player->walk_direction == 0)
		return ;
	move_step = player->move_speed;
	rotation = player->rotation_angle;
	if (player->walk_direction == 's')
		move_step = (-1) * player->move_speed;
	else if (player->walk_direction == 'a')
	{
		move_step = (-1) * player->move_speed;
		rotation = player->rotation_angle + deg_to_rad(90);
	}
	else if (player->walk_direction == 'd')
		rotation = player->rotation_angle + deg_to_rad(90);
	player->x += cos(rotation) * move_step;
	player->y += sin(rotation) * move_step;
	if (!ft_strchr("0NSEW", grid[(int)player->y][(int)player->x]))
	{
		player->x -= cos(rotation) * move_step;
		player->y -= sin(rotation) * move_step;
	}
}

void	update_player_orientation(t_player *player)
{
	double	rotation;

	if (player->turn_direction == 0)
		return ;
	rotation = player->turn_direction * player->rotation_speed;
	player->rotation_angle += rotation;
}
