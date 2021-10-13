/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:18:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 19:05:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_sprites.h"

/*
** Draws all the visible sprites
** @param:	- [t_game *] root struct
*/

void	draw_sprites(t_game *game)
{
	int			i;
	t_sprite	*sprite;

	i = -1;
	while (++i < game->scene.total_sprites)
	{
		sprite = &game->scene.sprites[i];
		if (sprite->is_visible)
			draw_single_sprite(game, &game->scene.sprites[i]);
	}
}

/*
** Draws a sprite
** @param:	- [t_game *] root struct
**			- [t_sprite *] sprite being drawn
** Line-by-line comments:
** @11		The closer I am from the sprite, the thicker its pixel will be
** @13-25	The total width of the sprite will be tex.width * column width
** @18		posX is the position in the screen in pixels. I go from the rect.x
**			which is the left-most position of the sprite and I move to the
**			right. (i - 1) * column_width + j is the amount of sprite strips
**			already drawn
** @19		Checks if we are within the screen width
** @20		Checks if the sprite isn't being a wall
** @22		Draws one column at a time of the sprite
*/

void	draw_single_sprite(t_game *game, t_sprite *sprite)
{
	t_rect	rect;
	double	column_width;
	int		i;
	int		j;
	int		pos_x;

	rect.height = get_sprite_height(game, sprite->distance);
	rect.y = get_y_sprite_position(game, rect.height);
	rect.x = get_x_sprite_position(game, sprite, rect.height);
	rect.sprite = sprite;
	column_width = rect.height / sprite->tex->height;
	i = -1;
	while (++i < sprite->tex->width)
	{
		j = -1;
		while (++j < column_width)
		{
			pos_x = (int)(rect.x + (i - 1) * column_width + j);
			if (pos_x >= 0 && pos_x <= game->scene.res.width - 1
				&& sprite->distance < game->rays.arr[pos_x].size)
			{
				draw_sprite_strip(&rect, game, i, pos_x);
			}
		}
	}
}

double	get_sprite_height(t_game *game, double distance)
{
	double	scaled_distance;
	double	sprite_height;

	scaled_distance = distance * SCALE;
	sprite_height = (SCALE / scaled_distance) * game->rays.dist_proj_plane;
	return (sprite_height);
}

/*
** Gets the vertical position of the beginning of the sprite
** @param:	- [t_game *] root struct
**			- [double] sprite height
** @return:	[int] y coordinate
** Line-by-line comments:
** @5		I go to the horizontal center of the screen
** @6-7		As I know the sprite will be horizontally centered (as are all
**			the walls) I just need to add half the height of the sprite to find
**			where it should begin
** @8-9		Edge case: I'm so close to the sprite that it's height is higher
**			than screen height then it begin draw at the top of the screen
*/

int		get_y_sprite_position(t_game *game, double sprite_height)
{
	int	center_screen;
	int	center_sprite;
	int	y;

	center_screen = game->scene.res.height / 2;
	center_sprite = sprite_height / 2;
	y = center_screen - center_sprite;
	if (y < 0)
		y = 0;
	return (y);
}

/*
** Gets the horizontal position of the beginning of the sprite
** @param:	- [t_game *] root struct
**			- [t_sprite *] sprite being drawn
**			- [double] sprite width (which is always equals to its height
**					   because we are working with textures)
** @return:	[int] x coordinate
** Line-by-line comments:
** @7		Exactly the same rationale as in get_y_sprite_position()
** @8		Here the center_sprite is the opposite and dist_proj_plane is the
**			adjacent
*/

int		get_x_sprite_position(t_game *game,
							t_sprite *sprite,
							double sprite_width)
{
	double	center_sprite;
	int		center_screen;
	double	begin_sprite;

	center_screen = game->scene.res.width / 2;
	center_sprite = tan(sprite->rotation_angle) * game->rays.dist_proj_plane;
	begin_sprite = center_screen + center_sprite - sprite_width / 2;
	return (begin_sprite);
}
