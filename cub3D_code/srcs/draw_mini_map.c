/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:28:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/06 14:25:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_mini_map.h"

void	draw_mini_map(t_game *game)
{
	draw_map(game);
	draw_player(game);
}

void	draw_map(t_game *game)
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
			rect.x = j * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.y = i * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.width = game->scene.mini_map_tile_size;
			rect.height = game->scene.mini_map_tile_size;
			rect.border_color = 0x0014213d;
			rect.border_width = 1;
			rect.fill_color = get_fill_color(game->scene.map.grid[i][j]);
			draw_rect(&rect, game->mlx.img.data, game->scene.res.width);
		}
	}
}

void	draw_player(t_game *game)
{
	t_circle	circle;
	// t_line		line;
	double		tile_size;

	tile_size = game->scene.mini_map_tile_size;
	draw_rays(game);
	game->player.radius =  tile_size / 2;
	circle.x = game->player.x * tile_size + MINIMAP_OFFSET;
	circle.y = game->player.y * tile_size + MINIMAP_OFFSET;
	circle.radius = game->player.radius;
	circle.fill_color = 0x00e63946;
	while (circle.radius--)
		draw_circle(&circle, circle.fill_color,
		game->mlx.img.data, game->scene.res.width);
	// line.begin_x = game->player.x * tile_size + MINIMAP_OFFSET;
	// line.begin_y = game->player.y * tile_size + MINIMAP_OFFSET;
	// line.end_x = game->player.x * tile_size	+ MINIMAP_OFFSET
	// 			+ cos(game->player.rotation_angle) * tile_size;
	// line.end_y = game->player.y * tile_size + MINIMAP_OFFSET
	// 			+ sin(game->player.rotation_angle) * tile_size;
	// line.color = 0x00e63946;
	// draw_line(&line, game->mlx.img.data, game->scene.res.width);
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

void	draw_rays(t_game *game)
{
	int		i;
	t_line	line;
	double	tile_size;

	tile_size = game->scene.mini_map_tile_size;
	i = -1;
	while (++i < game->rays.total_rays)
	{
		line.begin_x = game->player.x * tile_size + MINIMAP_OFFSET;
		line.begin_y = game->player.y * tile_size + MINIMAP_OFFSET;
		line.end_x = game->player.x * tile_size	+ MINIMAP_OFFSET
					+ cos(game->rays.arr[i].angle) * tile_size * game->rays.arr[i].size;
		line.end_y = game->player.y * tile_size + MINIMAP_OFFSET
					+ sin(game->rays.arr[i].angle) * tile_size * game->rays.arr[i].size;
		line.color = 0x00F6B8BD;
		draw_line(&line, game->mlx.img.data, game->scene.res.width);
	}
}
