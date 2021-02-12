/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:46:54 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 20:52:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_sprites.h"

/*
** Finds the angle that the sprite needs to have to be facing the player
** @param:	- [t_game *] root struct
**			- [t_sprite *] the sprite that we are currently updating
** Line-by-line comments:
** @8		Makes sure the angle is between 0 and 2 * PI
*/

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

/*
** Determines if the sprite is in the player's FOV
** @param:	- [t_game *] root struct
**			- [t_sprite *] the sprite that we are currently updating
** Line-by-line comments:
** @3		Going back to atan2(dy, dx) value by adding the player's angle.
**			Saves a few costly computations
** @5-9		Sort of a normalization
** @10		We are checking for FOV / 2 because it appear in the peripherals
**			of the player. We are adding 4° to take into account that we are
**			checking the visibility based on the 0.5 / 0.5 position in the
**			grid. So the sprite will need to appear before in view
*/

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
	if (delta_angle < game->rays.view_angle / 2 + deg_to_rad(4))
		sprite->is_visible = 1;
	else
		sprite->is_visible = 0;
}

/*
** Gets distance between sprite and player. Not why raycasting but simply
** by knowing before hand the position of every sprite. The moving part here
** being the player
** @param:	- [t_game *] root struct
**			- [t_sprite *] the sprite that we are currently updating
*/

void	update_sprite_distance(t_game *game, t_sprite *sprite)
{
	double		dx;
	double		dy;

	dx = sprite->x - game->player.x;
	dy = sprite->y - game->player.y;
	sprite->distance = sqrt(pow(dx, 2) + pow(dy, 2));
}

/*
** Orders the sprites from farther to closer. Sprites needs to be printed in
** that order because the closer goes on top the farther pixel-wise
** @param:	- [t_game *] root struct
**			- [t_sprite *] array of sprites to be ordered
*/

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
			if (sprites[j].distance < sprites[j + 1].distance)
			{
				tmp = sprites[j];
				sprites[j] = sprites[j + 1];
				sprites[j + 1] = tmp;
			}
		}
	}
}
