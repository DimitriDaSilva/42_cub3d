/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:21:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 09:56:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_scene.h"

void	get_map(int fd, char *line, t_scene *scene)
{
	scene->map = cpy_map(fd, line);
	scene->map_width = get_width(scene->map);
	scene->map_height = get_height(scene->map);
	scene->map = convert_tabs_to_spaces(scene->map, scene);
}

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
