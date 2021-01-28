/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/28 20:06:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int my_key_func(int keycode, void *param)
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
		ft_printf("Scene description file missing\n");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_printf("Error\nCould not open file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	get_scene(fd, &scene);
	printf("Resolution[0] = %d\n", scene.resolution[0]);
	printf("Resolution[1] = %d\n", scene.resolution[1]);
	printf("North texture = %s\n", scene.north_texture);
	printf("South texture = %s\n", scene.south_texture);
	printf("West texture = %s\n", scene.west_texture);
	printf("East texture = %s\n", scene.east_texture);
	printf("Sprite texture = %s\n", scene.sprite_texture);
	printf("Floor_color[0] = %d\n", scene.floor_color[0]);
	printf("Floor_color[1] = %d\n", scene.floor_color[1]);
	printf("Floor_color[2] = %d\n", scene.floor_color[2]);
	printf("Ceilling_color[0] = %d\n", scene.ceilling_color[0]);
	printf("Ceilling_color[1] = %d\n", scene.ceilling_color[1]);
	printf("Ceilling_color[2] = %d\n", scene.ceilling_color[2]);
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	// is_map_valid(&map);
	// render_scene(&map);
	free_scene(&scene);
	return (0);
}

void		free_scene(t_scene *scene)
{
	free(scene->north_texture);
	free(scene->south_texture);
	free(scene->west_texture);
	free(scene->east_texture);
	free(scene->sprite_texture);
}
