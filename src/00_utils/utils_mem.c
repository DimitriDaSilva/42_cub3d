/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:31:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 17:51:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_mem.h"

void	free_game(t_game *game)
{
	free_scene(&game->scene);
}

void	free_scene(t_scene *scene)
{
	free(scene->no_tex);
	free_map(&scene->map);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		free(map->grid[i]);
	}
	free(map->grid);
}
