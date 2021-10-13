/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:24:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 17:21:25 by dds              ###   ########.fr       */
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
** been set (different from 0) and they are greater than 0. We'll cap the
** resolution to the one of the display of the user resolution
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
		printf("Error\nInvalid resolution.\n");
		exit(EXIT_SUCCESS);
	}
	if (MAX_RES_WIDTH < res->width)
		res->width = MAX_RES_WIDTH;
	if (MAX_RES_HEIGHT < res->height)
		res->height = MAX_RES_HEIGHT;
}

/*
** Just checking if the path has been given and if it works (open / close)
** @param:	- [char *] file name with directory path
**			- [char *] name of the texture we are checking
*/

void	check_texture(char *texture_path, char *texture_name)
{
	int	fd;

	if (texture_path == 0)
	{
		printf("Error\nThe %s is either missing or poorly "
					"formatted.\n", texture_name);
		exit(EXIT_SUCCESS);
	}
	if (!check_extension(texture_path, ".xpm"))
	{
		printf("Error\nFile %s doesn't have xpm extension\n", texture_name);
		exit(EXIT_SUCCESS);
	}
	if ((fd = open(texture_path, O_RDONLY)) == -1)
	{
		printf("Error\nCould not open the %s: "
					"%s.\n", texture_name, texture_path);
		exit(EXIT_SUCCESS);
	}
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file %s.\n", texture_path);
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
		printf("Error\nThe %s is either missing or poorly "
					"formatted.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	else if (255 < color->r || 255 < color->g || 255 < color->b)
	{
		printf("Error\nThe RGB code for the %s is "
					"incorrect.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	color->argb = create_argb(0, color->r, color->g, color->b);
}
