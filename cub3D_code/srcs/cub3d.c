/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 12:22:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		my_key_func(int keycode, void *param)
{
	(void)param;
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_scene	scene;

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
	init_scene(&scene);
	get_scene(fd, &scene);
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	check_scene(&scene, argv[1]);
	// render_scene(&map);
	free_scene(&scene);
	return (0);
}

void	init_scene(t_scene *scene)
{
	ft_memset(scene->resolution, -1, 2 * sizeof(int));
	scene->north_texture = 0;
	scene->south_texture = 0;
	scene->west_texture = 0;
	scene->east_texture = 0;
	scene->sprite_texture = 0;
	ft_memset(scene->floor_color, -1, 3 * sizeof(int));
	ft_memset(scene->ceilling_color, -1, 3 * sizeof(int));
	scene->map = 0;
}
