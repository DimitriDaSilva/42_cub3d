/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene_valid2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:24:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 09:38:26 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_scene_valid.h"

void	check_map(t_scene *scene)
{
	if (scene->map == 0)
	{
		ft_printf("Error\nThe map is missing.\n");
		exit(EXIT_SUCCESS);
	}
	else if (!is_map_enclosed(scene->map, scene->map_height, scene->map_width))
	{
		ft_printf("Error\nThe map is not enclosed.\n");
		exit(EXIT_SUCCESS);
	}
	else if (!has_one_start_position(scene->map))
	{
		ft_printf("Error\nThe map has 0 or more than 1 start position.\n");
		exit(EXIT_SUCCESS);
	}
}

int		is_map_enclosed(char **map, int height, int width)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1')
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
					return (0);
				else if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' ' ||
						map[i - 1][j + 1] == ' ' || map[i][j + 1] == ' ' ||
						map[i + 1][j + 1] == ' ' || map[i + 1][j] == ' ' ||
						map[i + 1][j - 1] == ' ' || map[i][j - 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

int		has_one_start_position(char **map)
{
	int count;
	int i;
	int j;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		// printf("Map[i]: \"%s\"\n", map[i]);
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				count++;
		}
	}
	return (count == 1);
}
