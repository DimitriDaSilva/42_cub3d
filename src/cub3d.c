/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/24 10:17:04 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Program that creates a raycasting engine. It creates a map based on the .cub
** file passed as first argument. If --save is 2nd argument, the program saves
** the first image of the game and quits.
** @param:	- [int] argc
**			- [char **] argv
** Line-by-line comments:
** @4		Based on the arguments, assigns game.mode either "SAVE" or "PLAY"
** @11		In order to parse the .cub file only once, I extract the
**			information (get_scene()) and then I analyse it to determin
**			if the .cub is valid (check_scene()). For instance, some fields
**			of the t_scene struct could remain empty if it's invalid
*/

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	game;

	check_arguments(argc, argv, game.mode);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCould not open file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	get_scene(fd, &game.scene);
	int i = 0;
	while (game.scene.map.grid[i] != 0)
	{
		printf("%s\n", game.scene.map.grid[i]);
		i++;
	}
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	check_scene(&game.scene);
	render_game(&game);
	return (0);
}
