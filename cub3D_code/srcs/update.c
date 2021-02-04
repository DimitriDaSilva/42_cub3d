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

/*
** Between each frame, we check if the values of our struct have to be update
** because of user interactions (mouse motions or key presses)
** @param:	- [t_game *] root struct
*/

void	update(t_game *game)
{
	update_player_position(&game->player, game->scene.map.grid);
	update_player_orientation(&game->player);
	update_rays(game);
}

/*
** Updating the player position based on the WASD movement
** @param:	- [t_player *] player struct
**			- [char **] map formatted in a 2d array of chars
** Line-by-line comments:
** @4-5		Case: the user hasn't pressed WASD
** @6-7		Case: moving front (i.e. W key press). Default case as if other key
**			than W pressed one or both values will get overwritten
** @8-9		Case: moving back (i.e. S key press). Same orientation but the
**			opposite way
** @10-14	Case: moving left (i.e. A key press). We are looking right and
**			moving backward
** @15-16	Case: moving right (i.e. D key press). We are looking right and
**			moving forward
** @17-18	Updating the positions of the player. Here move_step = hypotenuse
**			because we know the distance to cross
** @17		Adding to x the adjacent (go left...)
** @18		Adding to y the opposite (...and up)
** @19-24	If the new position is in a wall, then we go back to previous
**			position
*/

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
	if (ft_strchr("12", grid[(int)player->y][(int)player->x]))
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

void	update_rays(t_game *game)
{
	int		i;
	double	ray_angle;

	ray_angle = game->player.rotation_angle - game->scene.view_angle / 2;
	i = -1;
	while (++i < game->rays.total_rays)
	{
		game->rays.arr[i].angle = ray_angle;
		cast_ray(&game->rays.arr[i], &game->scene.map, &game->player);
		ray_angle += game->scene.view_angle / game->rays.total_rays;
	}
}
