/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_scene2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:22:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 11:17:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ready_scene.h"

void	get_map_items(t_scene *scene, t_map *map)
{
	char	sprite_found;
	int 	i;
	int 	j;

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
				add_sprite(scene, j, i, sprite_found);
				scene->total_sprites++;
			}
		}
	}
}

void	add_sprite(t_scene *scene, int x, int y, char sprite)
{
	int	last_sprite_index;

	if (scene->total_sprites == 0)
	{
		if (!ft_malloc((void **)&scene->sprites, 1, sizeof(t_sprite)))
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
	scene->sprites[last_sprite_index].tex = get_sprite_tex(scene, sprite);
}

t_texture	*get_sprite_tex(t_scene *scene, char sprite)
{
	(void)sprite;
	return (&scene->sprite_tex);
}