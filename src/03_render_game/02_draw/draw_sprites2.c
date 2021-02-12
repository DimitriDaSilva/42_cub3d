/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:53:02 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 22:55:18 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_sprites.h"

/*
** Draws one column of the sprite
** @param:	- [t_rect *] rect struct with basic info
**			- [t_game *] root struct
**			- [int] x position inside the texture
**			- [int] current x position in the full image being drawn
** Line-by-line comments:
** @7		The farther the player is from the screen, the less pixels it has
**			to draw, so the step are heigher the farther he is from the sprite
** @12		The texPos is getting caped to the height of the texture
**			(e.g. 63) through a bitwise operation &
** @14-15	Like in all 1D array that mimic 2D, the formula is:
**			arr[y * width_arr + x] because I go through one line (y * width)
**			and then some (x)
** @16-17	Edge case: the None value in a bitmap file gives a negative value.
**			I ignore None value, they are treated as transparent
** @18-19	Adding the color to the image
**			Weird bug from Norminette forces me to have very verbose index
**			Instead of (rect->y + y) * game->scene.res.width
*/

void	draw_sprite_strip(t_rect *rect, t_game *game, int x_tex, int x_img)
{
	double	step;
	double	texPos;
	int		y;
	int		y_tex;
	int		color;

	step = 1.0 * rect->sprite->tex->height / rect->height;
	texPos = (rect->y - game->scene.res.height / 2 + rect->height / 2) * step;
	y = -1;
	while (++y < rect->height && y < game->scene.res.height)
	{
		y_tex = (int)texPos & (rect->sprite->tex->height - 1);
		texPos += step;
		color = rect->sprite->tex->img.data[y_tex
			* rect->sprite->tex->height + x_tex];
		if (color < 0)
			continue ;
		game->mlx.img.data[(rect->y * game->scene.res.width)
			+ (y * game->scene.res.width) + x_img] = color;
	}
}
