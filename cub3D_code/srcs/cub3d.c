/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/29 21:15:02 by dda-silv         ###   ########.fr       */
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
	// print_scene(&scene);
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	is_scene_valid(&scene, argv[1]);
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

void	print_scene(t_scene *scene)
{
	printf("Resolution[0] = %d\n", scene->resolution[0]);
	printf("Resolution[1] = %d\n", scene->resolution[1]);
	printf("North texture = %s\n", scene->north_texture);
	printf("South texture = %s\n", scene->south_texture);
	printf("West texture = %s\n", scene->west_texture);
	printf("East texture = %s\n", scene->east_texture);
	printf("Sprite texture = %s\n", scene->sprite_texture);
	printf("Floor_color[0] = %d\n", scene->floor_color[0]);
	printf("Floor_color[1] = %d\n", scene->floor_color[1]);
	printf("Floor_color[2] = %d\n", scene->floor_color[2]);
	printf("Ceilling_color[0] = %d\n", scene->ceilling_color[0]);
	printf("Ceilling_color[1] = %d\n", scene->ceilling_color[1]);
	printf("Ceilling_color[2] = %d\n", scene->ceilling_color[2]);
	int i = 0;
	while (scene->map[i] != 0)
	{
		printf("%s\n", scene->map[i]);
		i++;
	}
	// for (int i = 0; scene->map[i]; i++)
	// {
	// 	printf("%s\n", scene->map[i]);
	// }
}
