/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 08:52:48 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	game;

	check_arguments(argc, argv, game.mode);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCould not open file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	get_scene(fd, &game.scene);
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	check_scene(&game.scene);
	render_game(&game);
	return (0);
}
