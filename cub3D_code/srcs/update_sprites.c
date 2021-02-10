/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:46:54 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 15:11:38 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_sprites.h"

void	update_sprite_angle(t_game *game, t_sprite *sprite)
{
	double		dx;
	double		dy;
	double		angle;

	dx = sprite->x - game->player.x;
	dy = sprite->y - game->player.y;
	angle = atan2(dy, dx) - game->player.rotation_angle;
	sprite->rotation_angle = normalize_radian(angle);
}

void	update_sprite_visibility(t_game *game, t_sprite *sprite)
{
	double		delta_angle;

	delta_angle = sprite->rotation_angle + game->player.rotation_angle;
	delta_angle = game->player.rotation_angle - delta_angle;
	if (delta_angle < -M_PI)
		delta_angle += 2.0 * M_PI;
	if (delta_angle > M_PI)
		delta_angle -= 2.0 * M_PI;
	delta_angle = fabs(delta_angle);
	// if (delta_angle < game->rays.view_angle / 2 + deg_to_rad(4))
	// 	sprite->is_visible = 1;
	if (delta_angle < game->rays.view_angle / 2)
		sprite->is_visible = 1;
	else
		sprite->is_visible = 0;
}

void	update_sprite_distance(t_game *game, t_sprite *sprite)
{
	double		dx;
	double		dy;

	dx = sprite->x - game->player.x;
	dy = sprite->y - game->player.y;
	sprite->distance = sqrt(pow(dx, 2) + pow(dy, 2));
}

void	update_sprites_order(t_game *game, t_sprite *sprites)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = -1;
	while (++i < game->scene.total_sprites)
	{
		j = -1;
		while (++j < game->scene.total_sprites - 1)
		{
			if (sprites[j].distance > sprites[j + 1].distance)
			{
				tmp = sprites[j];
				sprites[j] = sprites[j + 1];
				sprites[j + 1] = tmp;
			}
		}
	}
}
