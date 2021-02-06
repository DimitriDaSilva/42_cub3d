/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 08:49:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/06 10:17:41 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_window.h"

void	create_window(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	check_user_res(&game->mlx, &game->scene.res);
	set_mini_map_size(&game->scene);
	set_rays(game);
	game->rays.view_angle = deg_to_rad(VIEW_ANGLE);
	game->rays.dist_proj_plane = (game->scene.res.width / 2)
								/ (tan(game->rays.view_angle / 2));
	load_texture(game->mlx.mlx_ptr, &game->scene.no_tex);
	load_texture(game->mlx.mlx_ptr, &game->scene.so_tex);
	load_texture(game->mlx.mlx_ptr, &game->scene.we_tex);
	load_texture(game->mlx.mlx_ptr, &game->scene.ea_tex);
	load_texture(game->mlx.mlx_ptr, &game->scene.sprite_tex);
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

void	load_texture(void *mlx, t_texture *texture)
{
	texture->img.img_ptr = mlx_xpm_file_to_image(mlx, texture->path,
							&texture->width, &texture->height);
	texture->img.data = (int *)mlx_get_data_addr(texture->img.img_ptr,
											&texture->img.bpp,
											&texture->img.size_l,
											&texture->img.endian);
}
