/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:24:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:56:52 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_scene.h"

/*
** @param:	- [t_scene *] a struct that holds the data used to render the game
*/

void	check_map(t_map *map)
{
	if (map->grid == 0)
	{
		printf("Error\nThe map is missing.\n");
		exit(EXIT_SUCCESS);
	}
	else if (!is_map_enclosed(map->grid, map->height, map->width))
	{
		printf("Error\nThe map is not enclosed.\n");
		exit(EXIT_SUCCESS);
	}
	else if (!has_one_start_position(map->grid))
	{
		printf("Error\nThe map has 0 or more than 1 start position.\n");
		exit(EXIT_SUCCESS);
	}
}

/*
** A valid maps needs to be bordered with 1 representing the walls
** @param:	- [char **] array of strings representing the map.
**                      All string have the same length
**			- [int] height of the map
**			- [int] width of the map
** @return:	[int] true or false
** Line-by-line comments:
** @10		We are parsing the map stopping each time we find a non-1
**			characters and check the 2 cases for which it could me the map
**			is not enclosed
**			The order of these 2 checks is important. The opposite could lead
**			to SEGFAULT in some cases where we are in the borders of the map
** @12-13	Case: the non-1 characters is positioned on the edges of the map
** 14-18	Case: there is a space on one of the 8 boxes around that position
*/

int		is_map_enclosed(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
					return (0);
				else if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' '
					|| map[i - 1][j + 1] == ' ' || map[i][j + 1] == ' '
					|| map[i + 1][j + 1] == ' ' || map[i + 1][j] == ' '
					|| map[i + 1][j - 1] == ' ' || map[i][j - 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

/*
** To be valid the map needs to have exactly one start position
** @param:	- [char **] array of strings representing the map.
**                      All string have the same length
** @return:	[int] true or false
** Line-by-line comments:
** @16		If count == 1 is true, then 1 is returned. Else, 0
*/

int		has_one_start_position(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				count++;
		}
	}
	return (count == 1);
}
