/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:59:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 19:07:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls.h"

/*
** Draws one wall strip
** @param:	- [t_rect *] rect struct with basic info
**			- [int *] 1D array that represents the image being drawn
**			- [t_res *] res of the screen (width and height)
**			- [t_ray *] ray struct that is useful for the bitmap offset
** Line-by-line comments:
** @7		The farther the player is from the screen, the less pixels it has
**			to draw, so the step are heigher the farther he is from the sprite
** @9		Finds which part of the texture to use for the wall
** @12		The texPos is getting caped to the height of the texture
**			(e.g. 63) through a bitwise operation &
** @15-16	Like in all 1D array that mimic 2D, the formula is:
**			arr[y * width_arr + x] because I go through one line (y * width)
**			and then some (x)
**			Adding the color to the image
**			Weird bug from Norminette forces me to have very verbose index
**			Instead of (rect->y + y) * game->scene.res.width
*/

void	draw_wall_strip(t_rect *rect, int *img, t_res *res, t_ray *ray)
{
	int		y;
	int		y_tex;
	int		x_tex;
	double	step;
	double	tex_pox;

	step = 1.0 * rect->tex.height / rect->height;
	tex_pox = (rect->y - res->height / 2 + rect->height / 2) * step;
	x_tex = get_bitmap_offset(ray, rect->tex.width);
	y = -1;
	while (++y < rect->height && y < res->height)
	{
		y_tex = (int)tex_pox & (rect->tex.height - 1);
		tex_pox += step;
		img[(rect->y * res->width) + (y * res->width)
			+ rect->x] = rect->tex.img.data[y_tex * rect->tex.height + x_tex];
	}
}

/*
** Based on exactly where the ray hits the wall we can find which part of
** the texture to use for the wall
** @param:	- [t_ray *] ray that hit the wall being drawn
**			- [int] width of the texture
** @return:	[int] x position in the texture
** Line-by-line comments:
** @4		Knowing if this ray is an horizontal or a vertical (cf. cast_ray.c)
**			let's us know which ray coordinate will have a fractional part
**			because having it a wall, the coordinate are necessarely of the
**			format x:1.00/y:2.42 or x:1.42/y:2.00
** @7		Multiplying a number like 64 by another comprised between 0 and 1
**			caps the result to 64. Offset is an int as it will be used as an
**			array index
*/

int		get_bitmap_offset(t_ray *ray, int bitmap_width)
{
	double	remainder;
	int		offset;

	if (ray->side == 'H')
	{
		remainder = ray->x - floor(ray->x);
		offset = bitmap_width * remainder;
	}
	else
	{
		remainder = ray->y - floor(ray->y);
		offset = bitmap_width * remainder;
	}
	return (offset);
}
