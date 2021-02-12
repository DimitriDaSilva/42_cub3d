/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:22:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 17:58:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ready_game_sprites.h"

void	ready_game_sprites(t_game *game)
{
	get_map_items(&game->scene, &game->scene.map);
}

/*
** Parses the grid and adds a sprite each time it finds one
** @param:	- [t_scene *] scene struct
**			- [t_map *] map struct with grid, height and width
** @return:	[type] return_value
*/

void	get_map_items(t_scene *scene, t_map *map)
{
	int		i;
	int		j;

	scene->total_sprites = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == '2')
			{
				add_sprite(scene, j, i);
				scene->total_sprites++;
			}
		}
	}
}

/*
** Sprites are stored in an array of t_sprite
** @param:	- [t_scene *] scene struct
**			- [int] x position of the sprite in the grid
** @return:	[type] return_value
** Line-by-line comments:
** @3-8		If it's the first sprite added, I need to malloc. That way I'm
**			sure I can realloc on the standard case
** @9-16	It's not the first so we realloc to total + 1
** @18-19	The sprites need to be in the center of the grid boxes
*/

void	add_sprite(t_scene *scene, int x, int y)
{
	int	last_sprite_index;

	if (scene->total_sprites == 0)
	{
		scene->sprites = malloc(sizeof(t_sprite));
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
