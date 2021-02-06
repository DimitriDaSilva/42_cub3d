/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:18:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/06 09:41:56 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_sprites.h"

void	draw_sprites(t_game *game)
{
	t_rect	rect;

	rect.x = 200;
	rect.y = 200;
	rect.width = 64;
	rect.height = 64;
	rect.border_width = 0;
	rect.tex = game->scene.no_tex;
	draw_rect_texture(&rect, game->mlx.img.data, game->scene.res.width);
	rect.x = 264;
	draw_rect_texture(&rect, game->mlx.img.data, game->scene.res.width);
}

void	draw_rect_texture(t_rect *rect, int *img, int res_width)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;
	int	color;
	int	a;
	int	r;
	int	g;
	int	b;


	rect->border_width--;
	i = -1;
	while (++i < rect->height)
	{
		j = -1;
		while (++j < rect->width)
		{
			// color = add_shade(0, rect->tex.img.data[i]);
			color = rect->tex.img.data[i];
			a = get_a(color);
			r = get_r(color);
			g = get_g(color);
			b = get_b(color);
			(void)a;
			(void)r;
			(void)g;
			(void)b;
			tmp_x = rect->x + j;
			tmp_y = rect->y + i;
			if (i <= 0 + rect->border_width || j <= 0 + rect->border_width ||
				i >= rect->height - 1 - rect->border_width ||
				j >= rect->width - 1 - rect->border_width)
				img[tmp_y * res_width + tmp_x] = 0x00FFFFFF;
			else
				img[tmp_y * res_width + tmp_x] = rect->tex.img.data[i * 64 + j];
		}
	}
}