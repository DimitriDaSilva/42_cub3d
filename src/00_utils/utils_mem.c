/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:31:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 23:12:38 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_mem.h"

void	free_game(t_game *game)
{
	free_scene(&game->mlx.mlx_ptr, &game->scene);
	free(game->rays.arr);
	free(game->mlx.img.data);
}

void	free_scene(void *mlx_ptr, t_scene *scene)
{
	(void)mlx_ptr;
	free(scene->no_tex.path);
	free(scene->no_tex.img.data);
	free(scene->so_tex.path);
	free(scene->so_tex.img.data);
	free(scene->we_tex.path);
	free(scene->we_tex.img.data);
	free(scene->ea_tex.path);
	free(scene->ea_tex.img.data);
	free(scene->sprite_tex.path);
	free(scene->sprite_tex.img.data);
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
