/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:28:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 17:05:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_mini_map.h"

void	draw_mini_map(t_game *game)
{
	t_rect	rect;
	int		i;
	int		j;

	i = -1;
	while (++i < game->scene.map.height)
	{
		j = -1;
		while (++j < game->scene.map.width)
		{
			if (game->scene.map.grid[i][j] == ' ')
				continue ;
			rect.x = j * TILE_SIZE + PIXEL_OFFSET;
			rect.y = i * TILE_SIZE + PIXEL_OFFSET;
			rect.width = TILE_SIZE;
			rect.height = TILE_SIZE;
			rect.stroke_color = 0x0014213d;
			rect.stroke_width = 0;
			rect.fill_color = get_fill_color(game->scene.map.grid[i][j]);
			draw_rect(&rect, game->mlx.img.data, game->scene.res.width);
		}
	}
}

int		get_fill_color(char grid_item)
{
	int color;

	if (grid_item == '1')
		color = 0x0014213d;
	else if (grid_item == '2')
		color = 0x00fca311;
	else
		color = 0x00FFFFFF;
	return (color);
}
