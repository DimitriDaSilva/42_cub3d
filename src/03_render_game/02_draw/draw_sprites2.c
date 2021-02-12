/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:53:02 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 11:53:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_sprites.h"

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
