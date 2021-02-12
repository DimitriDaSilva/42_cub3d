/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:52:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 17:01:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_scene.h"

/*
** This function parses the .cub file to extract the scene to render
** @param:	- [int] the file descriptor of the .cub file
**			- [t_scene *] a struct that holds the data used to render the game
** Line-by-line comments:
** @4-6		The scene struct needs to be initialized cleaned so that I can
**			check later if some fields were left empty or not. So I'm
**			preventing finding garbage values
** @8		The get_next_line function returns 1 when it has a found a new line,
**			0 when it has reached the end of the file and -1 when a error
**			occurred
** @10-17	The map and the rest of the data have very different formats so
**			we are here checking if the line is the beginning of the map to
**			split the 2 use cases
** @12		The line can contain spaces between each information. We are here
**			resolving this use case by spliting the string in substrings
*/

void	get_scene(int fd, t_scene *scene)
{
	char	*line;
	char	**strs;

	ft_memset(scene, 0, sizeof(t_scene));
	ft_memset(&scene->floor, -1, sizeof(t_color));
	ft_memset(&scene->ceilling, -1, sizeof(t_color));
	line = 0;
	while (get_next_line(fd, &line))
	{
		if (!is_map(line))
		{
			strs = ft_split(line, " \n\t\v\f\r");
			get_data(strs, scene);
			unload_strs(strs);
			free(strs);
			free(line);
		}
		else
			get_map(fd, line, &scene->map);
	}
	free(line);
}

/*
** Checks the identifier and fills the struct
** @param:	- [char **] array of information contained in one line of the
**                      .cub file
**			- [t_scene *] a struct that holds the data used to render the game
** Line-by-line comments:
** @5		Edge case: if something has been written after the correct path
**			we need to consider the information invalid. So here we simply
**			skip it and scene->north_texture remains NULL. Same pattern for
**			other fields
** @19-23	Edge case: use of an unknown specifier. We need to check that the
**			line is not simply a line feed first.
**			There are some cases where the identifier is correct and it will
**			still fall in this condition (e.g. edge case prevented by line 5)
**			but the subject's only requirement is to have "Error\n". I can live
**			with somewhat unaccurate error message if than can save me to
**			account for every little error edge case
*/

void	get_data(char **strs, t_scene *scene)
{
	if (strs[0] == 0)
		return ;
	else if (!ft_strcmp(strs[0], "R"))
		get_resolution(strs, &scene->res);
	else if (!ft_strcmp(strs[0], "NO") && strs[1] != 0 && strs[2] == 0)
		get_texture(strs[1], &scene->no_tex);
	else if (!ft_strcmp(strs[0], "SO") && strs[1] != 0 && strs[2] == 0)
		get_texture(strs[1], &scene->so_tex);
	else if (!ft_strcmp(strs[0], "WE") && strs[1] != 0 && strs[2] == 0)
		get_texture(strs[1], &scene->we_tex);
	else if (!ft_strcmp(strs[0], "EA") && strs[1] != 0 && strs[2] == 0)
		get_texture(strs[1], &scene->ea_tex);
	else if (!ft_strcmp(strs[0], "S") && strs[1] != 0 && strs[2] == 0)
		get_texture(strs[1], &scene->sprite_tex);
	else if (!ft_strcmp(strs[0], "F") && strs[1] != 0 && strs[2] == 0)
		get_color(strs[1], &scene->floor);
	else if (!ft_strcmp(strs[0], "C") && strs[1] != 0 && strs[2] == 0)
		get_color(strs[1], &scene->ceilling);
	else if (strs[0][0] != '\n')
	{
		ft_printf("Error\nUnknown identifier: %s", strs[0]);
		exit(EXIT_SUCCESS);
	}
}

/*
** Gets the resolution from the .cub file
** @param:	- [char **] array of information contained in one line of the
**                      .cub file
**			- [int *] array from the struct with 2 ints allocated
** Line-by-line comments:
** @1-2		Edge case 1: one of the resolution parameters has a letter or
**			symbol in it
**			Edge case 2: no numbers have been provided and strs[1] is NULL
** @3-4		Edge case: More than 2 numbers have been provided (either
**			3 numbers or more OR 2 numbers and no-space characters)
*/

void	get_resolution(char **strs, t_res *res)
{
	if (!ft_strisdigit(strs[1]) || !ft_strisdigit(strs[2]))
		return ;
	if (strs[3] != 0)
		return ;
	res->width = ft_atoi(strs[1]);
	res->height = ft_atoi(strs[2]);
}

/*
** Gets the texture from the .cub file
** @param:	- [char *] texture path found in the .cub file
**			- [t_texture *] texture struct with path, img, width and height
** Line-by-line comments:
** @line-line	comment
** @3-4		Edge case: a specifier is used twice. When it's the case we need
**			to return Error\n. So we are here overwritting with NULL the
**			path previously saved if not NULL. If NULL, then normal case, we
**			copy the path from the .cub file to the struct
*/

void	get_texture(char *texture_path, t_texture *texture)
{
	if (!texture->path)
		texture->path = ft_strdup(texture_path);
	else
		texture->path = 0;
}

/*
** Gets the color from the .cub file. Function works with both floor and
** ceilling
** @param:	- [char *] line extracted from the .cub file
**			- [int *] array from the struct with 3 ints allocated
** Line-by-line comments:
** @4-8		Edge case: the information for a same identifier has been provided
**			twice and we have already got a color saved
** @9-10	Edge case: more than one ',' is separating two numbers. The
**			ft_split function doesn't care how many ',' are in the string
**			so I created a function that returns the number of times a char is
**			found in a given string
** @15		Edge case: one of the colors has a letter or symbol in it
*/

void	get_color(char *str, t_color *color)
{
	int		i;
	char	**strs;

	if (color->r != -1)
	{
		color->r = -1;
		return ;
	}
	if (ft_strchr_freq(str, ',') != 2)
		return ;
	strs = ft_split(str, ",");
	if (!strs)
		return ;
	i = 0;
	while (strs[i] && ft_strisdigit(strs[i]))
		i++;
	if (i == 3)
	{
		color->r = ft_atoi(strs[0]);
		color->g = ft_atoi(strs[1]);
		color->b = ft_atoi(strs[2]);
	}
	unload_strs(strs);
	free(strs);
}
