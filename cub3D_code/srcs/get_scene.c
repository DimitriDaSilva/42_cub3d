/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:52:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/28 16:44:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_scene.h"

void	get_scene(int fd, t_scene *scene)
{
	char	*line;
	char	**strs;

	line = 0;
	while (get_next_line(fd, &line))
	{
		if (is_map(line))
		{
			get_map(line, &scene);
			break ;
		}
		strs = ft_split_chars(line, " \n\t\v\f\r");
		get_data(strs, &map);
		unload(strs);
		free(strs);
		free(line);
	}
	free(line);
}

static int	is_map(char *line, t_map *map)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("1 \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
	}
	return (check);
}

static void	get_data(char **strs, t_map *map)
{
	if (!ft_strcmp(*strs, "R"))
		get_resolution()
}

static void	unload_strs(char **strs)
{
	while (*strs)
		free(*strs++);
}
