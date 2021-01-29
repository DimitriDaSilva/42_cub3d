/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:24:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/29 18:02:20 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_scene_valid.h"

void	is_scene_valid(t_scene *scene, char *file)
{
	(void)scene;
	check_cub_extention(file);
	check_texture(scene->north_texture, "north texture");
	check_texture(scene->south_texture, "south texture");
	check_texture(scene->west_texture, "west texture");
	check_texture(scene->east_texture, "east texture");
	check_texture(scene->sprite_texture, "sprite texture");
	check_color(scene->floor_color, "floor color");
	check_color(scene->ceilling_color, "ceilling color");
}

void	check_cub_extention(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (!(len > 4 && !ft_strncmp(&file[len - 4], ".cub", 5)))
	{
		ft_printf("Error\nFile %s does not have the .cub extension.\n", file );
		exit(EXIT_SUCCESS);
	}
}

void	check_texture(char *texture_path, char *texture_name)
{
	int	fd;

	if (texture_path == 0)
	{
		ft_printf("Error\nThe s is missing.\n", texture_name);
		exit(EXIT_SUCCESS);
	}
	if ((fd = open(texture_path, O_RDONLY)) == -1)
	{
		ft_printf("Error\nCould not open %s: %s.\n", texture_name, texture_path);
		exit(EXIT_SUCCESS);
	}
	close(fd);
}

void	check_color(int arr[], char *color_name)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (arr[i] == -1 && i == 0)
		{
			ft_printf("Error\nThe %s is missing.\n", color_name);
			exit(EXIT_SUCCESS);
		}
		else if (arr[i] == -1)
		{
			ft_printf("Error\nThe RGB code for the %s does not contain 3 "
						"colors.\n", color_name);
			exit(EXIT_SUCCESS);
		}
		else if (arr[i] < 0 || 255 < arr[i])
		{
			ft_printf("Error\nThe RGB code for the %s is incorrect.\n", color_name);
			exit(EXIT_SUCCESS);
		}
	}
}
