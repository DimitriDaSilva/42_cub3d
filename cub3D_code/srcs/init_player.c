/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:41:14 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:38:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_player.h"

/*
** @param:	- [t_player *] player struct
** Line-by-line comments:
** @1-2		Current position of the player. Will receive start position
**			from the .cub file
** @3		Helf the size of the player in pixels (radius in geometry is )
** @4		Value that will be updated based on the key pressed
** 			-1 for back, 1 for front and 0 for still
** @5		Number of pixels per frame between two positions
** @6		Value that will be updated based on the key pressed
** 			-1 for left, 1 for right and 0 for still
** @7		Angle in radians where the player is facing. Will be receive
**			initial angle from .cub file
** @8		Numbers of angles per frame turned
*/

void	init_player(t_player *player, char **grid)
{
	player->radius = 4;
	player->walk_direction = 0;
	player->move_speed = 3.0;
	player->turn_direction = 0;
	player->rotation_speed = deg_to_rad(3);
	get_start_position(player, grid);
}

/*
** Gets start_position in the map. Stores it in an array of 3 ints:
** [0]: spawning orientation in ASCII value
** [1]: x position in the map (yes x = j)
** [2]: y position in the map (yes y = i)
** @param:	- [char **] array of strings reprensenting the map
**			- [int *] start_position with 3 ints allocated
*/

void	get_start_position(t_player *player, char **grid)
{
	int i;
	int j;

	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (ft_strchr("NSEW", grid[i][j]))
			{
				player->x = j;
				player->y = i;
				player->rotation_angle = get_starting_orientation(grid[i][j]);
			}
		}
	}
}

double	get_starting_orientation(char orientation)
{
	double radian;

	radian = 0;
	if (orientation == 'N')
		deg_to_rad(270);
	else if (orientation == 'S')
		deg_to_rad(90);
	else if (orientation == 'E')
		deg_to_rad(360);
	else if (orientation == 'W')
		deg_to_rad(180);
	return (radian);
}
