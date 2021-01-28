/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:52:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/28 23:46:39 by dda-silv         ###   ########.fr       */
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
			get_map(fd, line, scene);
			return ;
		}
		strs = ft_split(line, " \n\t\v\f\r");
		get_data(strs, scene);
		unload_strs(strs);
		free(strs);
		free(line);
	}
	free(line);
}

static int	is_map(char *line)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("1 \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);
}

static void	get_map(int fd, char *line, t_scene *scene)
{
	char	**strs;
	size_t	width;
	size_t	height;
	int		i;
	int		j;

	strs = cpy_map(fd, line);
	width = get_width(strs);
	height = get_height(strs);
	printf("Width: \"%ld\"\n", width);
	printf("Height: \"%ld\"\n", height);
	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			// if (strs[i][j] == '\t')
			// {
			// 	while ()
			// }
			j++;
		}
		i++;
	}
	unload_strs(strs);
	free(strs);
}

static char	**cpy_map(int fd, char *line)
{
	char	**strs;
	int		i;

	i = 0;
	if (!(strs = malloc((i + 2) * sizeof(char *))))
		exit(EXIT_FAILURE);
	strs[i++] = ft_strdup(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (!(strs = ft_realloc(strs,
								(i + 1) * sizeof(char *),
								(i + 2) * sizeof(char *))))
			exit(EXIT_FAILURE);
		strs[i++] = ft_strdup(line);
		free(line);
	}
	free(line);
	strs[i] = 0;
	return (strs);
}

static size_t	get_width(char **strs)
{
	size_t	max_length;
	size_t	length;

	max_length = 0;
	while (*strs)
	{
		length = 0;
		while (**strs)
		{
			if (*(*strs++) == '\t')
				length += 4;
			else
				length++;
		}
		if (length > max_length)
			max_length = length;
		strs++;
	}
	return (max_length);
}

static size_t	get_height(char **strs)
{
	size_t	length;

	length = 0;
	while (*strs)
	{
		strs++;
		length++;
	}
	return (--length);
}

static void	get_data(char **strs, t_scene *scene)
{
	if (strs[0] == 0)
		return ;
	else if (!ft_strcmp(strs[0], "R"))
	{
		scene->resolution[0] = ft_atoi(strs[1]);
		scene->resolution[1] = ft_atoi(strs[2]);
	}
	else if (!ft_strcmp(strs[0], "NO"))
		scene->north_texture = ft_strdup(strs[1]);
	else if (!ft_strcmp(strs[0], "SO"))
		scene->south_texture = ft_strdup(strs[1]);
	else if (!ft_strcmp(strs[0], "WE"))
		scene->west_texture = ft_strdup(strs[1]);
	else if (!ft_strcmp(strs[0], "EA"))
		scene->east_texture = ft_strdup(strs[1]);
	else if (!ft_strcmp(strs[0], "S"))
		scene->sprite_texture = ft_strdup(strs[1]);
	else if (!ft_strcmp(strs[0], "F"))
		get_color(strs[1], scene->floor_color);
	else if (!ft_strcmp(strs[0], "C"))
		get_color(strs[1], scene->ceilling_color);
}

static void get_color(char *str, int arr[])
{
	int		i;
	char	**strs;

	strs = ft_split(str, ",");
	i = 0;
	while (i < 3)
	{
		arr[i] = ft_atoi(strs[i]);
		i++;
	}
	unload_strs(strs);
	free(strs);
}

static void	unload_strs(char **strs)
{
	while (*strs)
		free(*strs++);
}
