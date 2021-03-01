/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:28:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 16:07:41 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_mini_map.h"

void	draw_mini_map(t_game *game)
{
	int	height_mini_map;

	height_mini_map = game->scene.mini_map_tile_size * game->scene.map.height
					+ MINIMAP_OFFSET * 2;
	if (height_mini_map > game->scene.res.height)
		return ;
	draw_map(game);
	draw_player(game, game->scene.mini_map_tile_size);
}

/*
** Draws the map of the mini map. Parses the 2D grid and each time if finds a
** non-space item, it prints a square of a color that depends on the item
** @param:	- [t_game *] root struct
** Line-by-line comments:
** @15-16		The minimap needs to be offset otherwise it would be straight
**				on the corner of the screen
** @18			The mini_map_tile_size is variable with the res width
** @20			The square could have border I chose not to here
*/

void	draw_map(t_game *game)
{
	t_rect	rect;
	int		i;
	int		j;
	char	grid_item;

	i = -1;
	while (++i < game->scene.map.height)
	{
		j = -1;
		while (++j < game->scene.map.width)
		{
			grid_item = game->scene.map.grid[i][j];
			if (grid_item == ' ')
				continue ;
			rect.x = j * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.y = i * game->scene.mini_map_tile_size + MINIMAP_OFFSET;
			rect.width = game->scene.mini_map_tile_size;
			rect.height = game->scene.mini_map_tile_size;
			rect.border_color = 0x0014213d;
			rect.border_width = 0;
			rect.fill_color = get_fill_color(&game->scene.floor, grid_item);
			draw_rect(&rect, game->mlx.img.data, game->scene.res.width);
		}
	}
}

/*
** Draws the player on top of the map. Player composed of a dot and the rays
** that were casted
** @param:	- [t_game *] root struct
** Line-by-line comments:
** @3		The rays go below the dot so they need to be printed first
** @4		I get seg fault for a radius very close to 0
** @9-10	The draw circle only draws the border of the circle so I'm filling
**			it by printing several times reducing its radius
*/

void	draw_player(t_game *game, double tile_size)
{
	t_circle	circle;

	draw_rays(game, tile_size);
	game->player.radius = ceil(tile_size / 2);
	circle.x = game->player.x * tile_size + MINIMAP_OFFSET;
	circle.y = game->player.y * tile_size + MINIMAP_OFFSET;
	circle.radius = game->player.radius;
	circle.fill_color = 0x00e63946;
	while (circle.radius--)
		draw_circle(&circle, game->mlx.img.data, game->scene.res.width);
}

int		get_fill_color(t_color *floor_color, char grid_item)
{
	int	color;

	if (grid_item == '1')
		color = floor_color->argb;
	else if (grid_item == '2')
		color = 0x00fca311;
	else
		color = 0x00FFFFFF;
	return (color);
}

/*
** Draws all the casted rays in the minimap
** @param:	- [t_game *] root struct
** Line-by-line comments:
** @5		Again, number of rays casted == res width
** @11		The size of the line is determined by the scale (tile_size) and
**			its grid length (rays.arr[i].size)
*/

void	draw_rays(t_game *game, double tile_size)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < game->scene.res.width)
	{
		line.begin_x = game->player.x * tile_size + MINIMAP_OFFSET;
		line.begin_y = game->player.y * tile_size + MINIMAP_OFFSET;
		line.end_x = game->player.x * tile_size + MINIMAP_OFFSET
			+ cos(game->rays.arr[i].angle)
			* tile_size * game->rays.arr[i].size;
		line.end_y = game->player.y * tile_size + MINIMAP_OFFSET
			+ sin(game->rays.arr[i].angle)
			* tile_size * game->rays.arr[i].size;
		line.color = 0x00F6B8BD;
		draw_line(&line, game->mlx.img.data, game->scene.res.width);
	}
}
