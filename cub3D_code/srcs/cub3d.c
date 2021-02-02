/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:16:18 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	int		fd;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nScene description file missing.\n");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_printf("Error\nCould not open file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	get_scene(fd, &game.scene);
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	check_scene(&game.scene, argv[1]);
	init_player(&game.player, game.scene.map.grid);
	render_scene(&game);
	// free_scene(&scene);
	return (0);
}


// void	free_scene(t_scene *scene)
// {
// 	free(scene->north_texture);
// 	free(scene->south_texture);
// 	free(scene->west_texture);
// 	free(scene->east_texture);
// 	free(scene->sprite_texture);
// 	if (scene->map)
// 	{
// 		unload_strs(scene->map);
// 		free(scene->map);
// 	}
// }
