/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:41:14 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 15:35:54 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ready_game_player.h"

/*
** @param:	- [t_player *] player struct
** Line-by-line comments:
** @1		Value that will be updated based on the key pressed
** 			-1 for back, 1 for front and 0 for still
** @2		Number of pixels per frame between two positions
** @3		Value that will be updated based on the key pressed
** 			-1 for left, 1 for right and 0 for still
** @4		Numbers of angles per frame turned
*/

void	ready_game_player(t_game *game)
{
	game->player.walk_direction = 0;
	game->player.move_speed = 0.15;
	game->player.turn_direction = 0;
	game->player.rotation_speed = deg_to_rad(4);
	get_starting_position(&game->player, game->scene.map.grid);
}

/*
** @param:	- [char **] array of strings reprensenting the map
**			- [int *] start_position with 3 ints allocated
** Line-by-line comments:
** @15		Erasing the start position from the grid to simplify edge cases
*/

void	get_starting_position(t_player *player, char **grid)
{
	int	i;
	int	j;

	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (ft_strchr("NSEW", grid[i][j]))
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				player->rotation_angle = get_starting_orientation(grid[i][j]);
				grid[i][j] = '0';
			}
		}
	}
}

double	get_starting_orientation(char orientation)
{
	double	radian;

	radian = 0;
	if (orientation == 'N')
		radian = deg_to_rad(270);
	else if (orientation == 'S')
		radian = deg_to_rad(90);
	else if (orientation == 'E')
		radian = deg_to_rad(360);
	else if (orientation == 'W')
		radian = deg_to_rad(180);
	return (radian);
}
