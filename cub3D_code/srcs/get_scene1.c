/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:52:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/01 08:23:59 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_scene.h"

/*
** This function parses the .cub file to extract the scene to render
** @param:	- [int] the file descriptor of the .cub file
**			- [t_scene *] a struct that holds the data used to render the game
** Line-by-line comments:
** @5		The get_next_line function returns 1 when it has a found a new line,
**			0 when it has reached the end of the file and -1 when a error
**			occurred
** @7-16	The map and the rest of the data have very different formats so
**			we are here checking if the line is the beginning of the map to
**			split the 2 use cases
** @9		The line can contain spaces between each information. We are here
**			resolving this use case by spliting the string in substrings
*/

void	get_scene(int fd, t_scene *scene)
{
	char	*line;
	char	**strs;

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
			get_map(fd, line, scene);
	}
	free(line);
}

/*
** Check if the line follows the pattern of a new line
** @param:	- [char *] a line read from the .cub file
** @return:	[int] 1 if follows the pattern. Else 0
** Line-by-line comments:
** @6-7		The list of valid characters will change if we add more features
**			to the game (e.g. ammo, treasures). Although a valid first line
** 			for a map can't contain characters other than 1 and space, we are
**			including them to provide more accurate error message
** @8-9		Only one 1 is enough to follow the correct map pattern
*/

int		is_map(char *line)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("012NSEW \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);
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
** @6		Edge case: a specifier is used twice. When it's the case we need
**			to return Error\n. So we are here overwritting with NULL the
**			path previously saved if not NULL. If NULL, then normal case, we
**			copy the path from the .cub file to the struct
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
		get_resolution(strs, scene->resolution);
	else if (!ft_strcmp(strs[0], "NO") && strs[2] == 0)
		scene->north_texture = !scene->north_texture ? ft_strdup(strs[1]) : 0;
	else if (!ft_strcmp(strs[0], "SO") && strs[2] == 0)
		scene->south_texture = !scene->south_texture ? ft_strdup(strs[1]) : 0;
	else if (!ft_strcmp(strs[0], "WE") && strs[2] == 0)
		scene->west_texture = !scene->west_texture ? ft_strdup(strs[1]) : 0;
	else if (!ft_strcmp(strs[0], "EA") && strs[2] == 0)
		scene->east_texture = !scene->east_texture ? ft_strdup(strs[1]) : 0;
	else if (!ft_strcmp(strs[0], "S") && strs[2] == 0)
		scene->sprite_texture = !scene->sprite_texture ? ft_strdup(strs[1]) : 0;
	else if (!ft_strcmp(strs[0], "F") && strs[2] == 0)
		get_color(strs[1], scene->floor_color);
	else if (!ft_strcmp(strs[0], "C") && strs[2] == 0)
		get_color(strs[1], scene->ceilling_color);
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

void	get_resolution(char **strs, int arr[])
{
	if (!ft_strisdigit(strs[1]) || !ft_strisdigit(strs[2]))
		return ;
	if (strs[3] != 0)
		return ;
	arr[0] = ft_atoi(strs[1]);
	arr[1] = ft_atoi(strs[2]);
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
** @14		Edge case: one of the colors has a letter or symbol in it
*/

void	get_color(char *str, int arr[])
{
	int		i;
	char	**strs;

	if (arr[0] != -1)
	{
		arr[0] = -1;
		return ;
	}
	if (ft_strchr_freq(str, ',') != 2)
		return ;
	if (!(strs = ft_split(str, ",")))
		return ;
	i = 0;
	while (strs[i] && ft_strisdigit(strs[i]))
	{
		arr[i] = ft_atoi(strs[i]);
		i++;
	}
	unload_strs(strs);
	free(strs);
}
