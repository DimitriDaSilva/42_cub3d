/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:59:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 12:26:10 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls.h"

void	draw_wall_strip(t_rect *rect, int *img, t_res *res, t_ray *ray)
{
	int		y;
	int		y_tex;
	int		x_tex;
	double	step;
	double	texPos;

	step = 1.0 * rect->tex.height / rect->height;
	texPos = (rect->y - res->height / 2 + rect->height / 2) * step;
	x_tex = get_bitmap_offset(ray, rect->tex.width);
	y = -1;
	while (++y < rect->height && y < res->height)
	{
		y_tex = (int)texPos & (rect->tex.height - 1);
		texPos += step;
		img[(rect->y * res->width) + (y * res->width) + rect->x]
			= rect->tex.img.data[y_tex * rect->tex.height + x_tex];
	}
}

int	get_bitmap_offset(t_ray *ray, int bitmap_width)
{
	double	remainder;
	int		offset;

	if (ray->side == 'H')
	{
		remainder = ray->x - floor(ray->x);
		offset = floor(bitmap_width * remainder);
	}
	else
	{
		remainder = ray->y - floor(ray->y);
		offset = floor(bitmap_width * remainder);
	}
	return (offset);
}
