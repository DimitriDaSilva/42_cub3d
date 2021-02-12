/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:22:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 16:41:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ready_game_sprites.h"

void	ready_game_sprites(t_game *game)
{
	get_map_items(&game->scene, &game->scene.map);
}

void	get_map_items(t_scene *scene, t_map *map)
{
	char	sprite_found;
	int		i;
	int		j;

	scene->total_sprites = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			sprite_found = map->grid[i][j];
			if (sprite_found == '2')
			{
				add_sprite(scene, j, i);
				scene->total_sprites++;
			}
		}
	}
}

void	add_sprite(t_scene *scene, int x, int y)
{
	int	last_sprite_index;

	if (scene->total_sprites == 0)
	{
		scene->sprites = malloc (sizeof(t_sprite));
		if (!scene->sprites)
			exit(EXIT_SUCCESS);
	}
	else
	{
		scene->sprites = ft_realloc(scene->sprites,
				scene->total_sprites * sizeof(t_sprite),
				(scene->total_sprites + 1) * sizeof(t_sprite));
		if (!scene->sprites)
			exit(EXIT_SUCCESS);
	}
	last_sprite_index = scene->total_sprites;
	scene->sprites[last_sprite_index].x = (double)x + 0.5;
	scene->sprites[last_sprite_index].y = (double)y + 0.5;
	scene->sprites[last_sprite_index].tex = &scene->sprite_tex;
}
