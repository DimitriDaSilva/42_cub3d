/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:24:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 12:30:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_scene.h"

/*
** @param:	- [t_scene *] a struct that holds the data used to render the game
*/

void	check_scene(t_scene *scene)
{
	check_resolution(&scene->res);
	check_texture(scene->no_tex.path, "north texture");
	check_texture(scene->so_tex.path, "south texture");
	check_texture(scene->we_tex.path, "west texture");
	check_texture(scene->ea_tex.path, "east texture");
	check_texture(scene->sprite_tex.path, "sprite texture");
	check_color(&scene->floor, "floor color");
	check_color(&scene->ceilling, "ceilling color");
	check_map(&scene->map);
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

void	check_resolution(t_res *res)
{
	if (res->width == 0 || res->height == 0)
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
	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCould not open the %s: "
					"%s.\n", texture_name, texture_path);
		exit(EXIT_SUCCESS);
	}
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file %s.\n", texture_path);
		exit(EXIT_FAILURE);
	}
}

/*
** @param:	- [int *] array with the 3 colors of the RGB code
**			- [char *] color name (either floor color or ceilling)
** Line-by-line comments:
** @1		-1 is the init value so it means that no value has been stored
*/

void	check_color(t_color *color, char *color_name)
{
	if (color->r == -1)
	{
		ft_printf("Error\nThe %s is either missing or poorly "
					"formatted.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	else if (255 < color->r || 255 < color->g || 255 < color->b)
	{
		ft_printf("Error\nThe RGB code for the %s is "
					"incorrect.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	color->argb = create_argb(0, color->r, color->g, color->b);
}
