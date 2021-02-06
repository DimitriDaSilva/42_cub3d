/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:44:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/06 19:34:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_graph.h"

void	draw_rect(t_rect *rect, int *img, int res_width)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;


	rect->border_width--;
	i = -1;
	while (++i < rect->height)
	{
		j = -1;
		while (++j < rect->width)
		{
			tmp_x = rect->x + j;
			tmp_y = rect->y + i;
			if (i <= 0 + rect->border_width || j <= 0 + rect->border_width ||
				i >= rect->height - 1 - rect->border_width ||
				j >= rect->width - 1 - rect->border_width)
				img[tmp_y * res_width + tmp_x] = rect->border_color;
			else
				img[tmp_y * res_width + tmp_x] = rect->fill_color;
		}
	}
}

void	draw_circle(t_circle *circle, int color, int *img, int res_width)
{
	double	angle;
	double 	x1;
	double 	y1;
	int		tmp_x;
	int		tmp_y;

	angle = 0;
	while (angle <= 360)
	{
		x1 = circle->radius * cos(deg_to_rad(angle));
		y1 = circle->radius * sin(deg_to_rad(angle));
		tmp_x = circle->x + (int)x1;
		tmp_y = circle->y + (int)y1;
		img[tmp_y * res_width + tmp_x] = color;
		angle += 0.1;
	}
}

void	draw_line(t_line *line, int *img, int res_width)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;


	delta_x = line->end_x - line->begin_x;
	delta_y = line->end_y - line->begin_y;
	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line->begin_x;
	pixel_y = line->begin_y;
	while (pixels)
	{
		img[(int)pixel_y * res_width + (int)pixel_x] = line->color;
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}
