/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:21:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 16:11:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_scene.h"

/*
** Gets the map from the .cub file
** @param:	- [int] fd of the .cub file
**			- [char *] first row of the map
**			- [t_scene *] a struct that holds the data used to render the game
** Line-by-line comments:
** @1		Extracts the map from the .cub file without changing the format
**			and stores it in a array of string. The string are here not
**			necessarely all of the same size
** @2-4		The map needs to be easy to parse to check if it's valid and to
**			render it. The change here made is to have all lines with the same
**			size filled with spaces when necessary. Also tabs are converted to
**			spaces (1 tab = 4 spaces)
*/

void	get_map(int fd, char *line, t_scene *scene)
{
	scene->map = cpy_map(fd, line);
	scene->map_width = get_width(scene->map);
	scene->map_height = get_height(scene->map);
	scene->map = convert_tabs_to_spaces(scene->map, scene);
}

/*
** Extracts the map from the .cub file
** @param:	- [int] fd of the .cub file
**			- [char *] first row of the map
** @return:	[char **] map stored in an array of strings
** Line-by-line comments:
** @5-6		Allocating the first char * to be able to use realloc in the
**			do... while loop (home-made do... while but still)
** @7-17	Had to use a do... while because of the edge case where we only
**			have one row in the map, I had memory leaks
**			Here I'm looping and storing in array of strings the map. Each
**			time I find a new line I increase the size of the array by one
*/

char	**cpy_map(int fd, char *line)
{
	char	**strs;
	int		i;

	i = 0;
	if (!(strs = malloc(sizeof(char *))))
		exit(EXIT_SUCCESS);
	while (1)
	{
		if (!(strs = ft_realloc(strs,
								(i + 1) * sizeof(char *),
								(i + 2) * sizeof(char *))))
			exit(EXIT_SUCCESS);
		strs[i++] = ft_strdup(line);
		free(line);
		if (!get_next_line(fd, &line))
			break ;
	}
	free(line);
	strs[i] = 0;
	return (strs);
}

/*
** In the map, spaces can be represented by tabs but should be accounted
** like 4 spaces
** @param:	- [char **] map stored in an array of strings
**			- [t_scene *] a struct that holds the data used to render the game
** @return:	[char **] map stored in array of strings with all row with
**                    with the same size
** Line-by-line comments:
** @10-12	In case the lenght of the current row is smaller than the longest
**			one, we enlarge it to make room for spaces
** @15-19	If we find a tab, we move the chars 4 places and fill the gap with
**			spaces
** @20-21	If the characters found is not a VALID_CHAR (i.e. "012NSEW "),
**			then it means it's the end of the string and we need to add spaces
**			until we reach j == scene->map_width
** @23		As we are overwritting the NULL terminator for the string
**			originally shorter than the map_width, we need to put it back
*/

char	**convert_tabs_to_spaces(char **strs, t_scene *scene)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < scene->map_height)
	{
		j = -1;
		len = ft_strlen(strs[i]);
		if (len < scene->map_width)
			if (!(strs[i] = ft_realloc(strs[i], len + 1, scene->map_width + 1)))
				exit(EXIT_SUCCESS);
		while (++j < scene->map_width)
		{
			if (strs[i][j] == '\t')
			{
				ft_memmove(&strs[i][j + 4], &strs[i][j + 1], len - j + 2);
				ft_strncpy(&strs[i][j], "    ", 4);
			}
			else if (!ft_strchr(VALID_CHARS, strs[i][j]))
				strs[i][j] = ' ';
		}
		strs[i][j] = '\0';
	}
	return (strs);
}

/*
** The width of the map is didacted by the longest string of the array. We need
** to adjust for potential tabs
** @param:	- [char **] map stored in an array of strings
** @return:	[size_t] width of the map
*/

size_t	get_width(char **strs)
{
	size_t	max_length;
	size_t	length;
	int		i;
	int		j;

	max_length = 0;
	i = 0;
	while (strs[i])
	{
		length = 0;
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == '\t')
				length += 4;
			else
				length++;
			j++;
		}
		if (length > max_length)
			max_length = length;
		i++;
	}
	return (max_length);
}

/*
** @param:	- [char **] map stored in an array of strings
** @return:	[size_t] height of the map
*/

size_t	get_height(char **strs)
{
	size_t	length;

	length = 0;
	while (*strs)
	{
		strs++;
		length++;
	}
	return (length);
}
