/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 08:49:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/04 19:30:00 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_window.h"

void	create_window(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	check_user_res(&game->mlx, &game->scene.res);
	set_mini_map_size(&game->scene);
	set_rays(game);
	game->scene.view_angle = deg_to_rad(VIEW_ANGLE);
	game->mlx.win = mlx_new_window(game->mlx.mlx_ptr,
									game->scene.res.width,
									game->scene.res.height,
									"Cub3d");
}

void	check_user_res(t_mlx *mlx, t_res *res)
{
	int	user_width;
	int	user_height;

	user_width = 0;
	user_height = 0;
	mlx_get_screen_size(mlx->mlx_ptr, &user_width, &user_height);
	if (user_width < res->width)
		res->width = user_width;
	if (user_height < res->height)
		res->height = user_height;
}

void	set_mini_map_size(t_scene *scene)
{
	scene->mini_map_tile_size = scene->res.width / MINIMAP_RATIO;
}

void	set_rays(t_game *game)
{
	int	total_rays;

	total_rays = game->scene.res.width / PIXELS_PER_RAY;
	game->rays.total_rays = total_rays;
	if (!(game->rays.arr = malloc(total_rays * sizeof(t_ray))))
		exit(EXIT_SUCCESS);
}
