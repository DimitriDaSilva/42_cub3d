/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:24:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 16:12:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_scene.h"

/*
** @param:	- [t_scene *] a struct that holds the data used to render the game
**			- [char	*] name of the file passed in as argument of the cub3d
*/

void	check_scene(t_scene *scene, char *file)
{
	check_cub_extention(file);
	check_resolution(scene->resolution);
	check_texture(scene->north_texture, "north texture");
	check_texture(scene->south_texture, "south texture");
	check_texture(scene->west_texture, "west texture");
	check_texture(scene->east_texture, "east texture");
	check_texture(scene->sprite_texture, "sprite texture");
	check_color(scene->floor_color, "floor color");
	check_color(scene->ceilling_color, "ceilling color");
	check_map(scene);
}

/*
** @param:	- [char	*] name of the file passed in as argument of the cub3d
** Line-by-line comments:
** @4		Before checking the extension, I need to check it's size otherwise
**			I risk doing a SEGFAULT
*/

void	check_cub_extention(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (!(len > 4 && !ft_strncmp(&file[len - 4], ".cub", 5)))
	{
		ft_printf("Error\nFile %s does not have the .cub extension.\n", file);
		exit(EXIT_SUCCESS);
	}
}

/*
** The only requirements of the resolution at this stage is that they have
** been set (different from -1) and they are greater than 0. Later in the
** program, we'll cap the resolution to the one of the display of the user
** resolution
** @param:	- [int *] array of 2 ints with the resolution value
** Line-by-line comments:
** @1		No need to check for resolution set lower than 0 because that would
**			require a '-' characters and get_resolution() prevented any
**			non-digit to being stored
*/

void	check_resolution(int arr[])
{
	if (arr[0] == -1 || arr[1] == -1 || arr[0] == 0 || arr[1] == 0)
	{
		ft_printf("Error\nInvalid resolution.\n");
		exit(EXIT_SUCCESS);
	}
}

/*
** @param:	- [char *] file name with directory path
**			- [char *] name of the texture we are checking
*/

void	check_texture(char *texture_path, char *texture_name)
{
	int	fd;

	if (texture_path == 0)
	{
		ft_printf("Error\nThe %s is either missing or poorly "
					"formatted.\n", texture_name);
		exit(EXIT_SUCCESS);
	}
	if ((fd = open(texture_path, O_RDONLY)) == -1)
	{
		ft_printf("Error\nCould not open the %s: "
					"%s.\n", texture_name, texture_path);
		exit(EXIT_SUCCESS);
	}
	close(fd);
}

/*
** @param:	- [int *] array with the 3 colors of the RGB code
**			- [char *] color name (either floor color or ceilling)
** Line-by-line comments:
** @6		-1 is the init value so it means that no value has been stored
*/

void	check_color(int arr[], char *color_name)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (arr[i] == -1 && i == 0)
		{
			ft_printf("Error\nThe %s is either missing or poorly "
						"formatted.\n", color_name);
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
			ft_printf("Error\nThe RGB code for the %s is "
						"incorrect.\n", color_name);
			exit(EXIT_SUCCESS);
		}
	}
}
