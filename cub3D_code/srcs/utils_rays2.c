/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:44:27 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/08 17:06:05 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_rays2.h"

double	normalize_radian(double radian)
{
	double	full_circle;

	full_circle = deg_to_rad(360);
	radian = fmod(radian, full_circle);
	if (radian < 0)
		radian += full_circle;
	return (radian);
}

void	add_sprite(t_ray *ray, double x, double y, char sprite)
{
	int	last_sprite_index;

	if (ray->total_sprites == 0)
	{
		if (!ft_malloc((void **)&ray->sprites, 1, sizeof(t_sprite)))
			exit(EXIT_SUCCESS);
	}
	else
	{
		ray->sprites = ft_realloc(ray->sprites,
									ray->total_sprites * sizeof(t_sprite),
									(ray->total_sprites + 1) * sizeof(t_sprite));
		if (!ray->sprites)
			exit(EXIT_SUCCESS);
	}
	ray->total_sprites++;
	last_sprite_index = ray->total_sprites - 1;
	ray->sprites[last_sprite_index].x = x;
	ray->sprites[last_sprite_index].y = y;
	ray->sprites[last_sprite_index].item = sprite;
}

void	merge_sprites(t_ray *ray, t_ray *tmp)
{
	int	new_total_sprites;

	if (tmp->total_sprites == 0)
		return ;
	if (ray->total_sprites == 0)
	{
		ray->total_sprites = tmp->total_sprites;
		ray->sprites = tmp->sprites;
		return ;
	}
	new_total_sprites = ray->total_sprites + tmp->total_sprites;
	ray->sprites = ft_realloc(ray->sprites,
								ray->total_sprites * sizeof(t_sprite),
								new_total_sprites * sizeof(t_sprite));
	if (!ray->sprites)
		exit(EXIT_SUCCESS);
	ft_memcpy(&ray->sprites[ray->total_sprites],
				tmp->sprites,
				tmp->total_sprites * sizeof(t_sprite));
	ray->total_sprites = new_total_sprites;
	free(tmp->sprites);
}
