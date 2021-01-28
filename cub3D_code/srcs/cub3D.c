/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/28 16:38:15 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	// is_map_valid(&map);
	// render_map(&map);
	return (0);
}