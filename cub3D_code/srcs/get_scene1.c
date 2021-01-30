/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:52:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 10:44:16 by dda-silv         ###   ########.fr       */
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

void	get_resolution(char **strs, int arr[])
{
	if (ft_strisdigit(strs[1]) && ft_strisdigit(strs[2]) && strs[3] == 0)
	{
		arr[0] = ft_atoi(strs[1]);
		arr[1] = ft_atoi(strs[2]);
	}
}

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
