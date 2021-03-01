/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:31:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 17:59:13 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_mem.h"

void	free_game(t_game *game)
{
	free_scene(&game->scene);
	free(game->rays.arr);
}

void	free_scene(t_scene *scene)
{
	free(scene->no_tex.path);
	free(scene->so_tex.path);
	free(scene->we_tex.path);
	free(scene->ea_tex.path);
	free(scene->sprite_tex.path);
	free_map(&scene->map);
	free(scene->sprites);
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
