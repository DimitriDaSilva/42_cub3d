/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/03 17:36:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_game.h"

void	render_game(t_game *game)
{
	create_window(game);
	set_event_hooks(game);
	mlx_loop_hook(game->mlx.mlx_ptr, render_next_frame, game);
	mlx_loop(game->mlx.mlx_ptr);
}

int		render_next_frame(void *my_struct)
{
	t_game	*game;

	game = my_struct;
	get_empty_img(&game->mlx, &game->scene.res);
	update(game);
	draw_background(game);
	draw_game(game);
	draw_mini_map(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.img_ptr);
	return (1);
}

void	get_empty_img(t_mlx *mlx, t_res *res)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, res->width, res->height);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
											&mlx->img.bpp,
											&mlx->img.size_l,
											&mlx->img.endian);
}

void	draw_background(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = game->scene.res.width;
	rect.height = game->scene.res.height;
	rect.border_width = 0;
	rect.fill_color = 0x00f1faee;
	draw_rect(&rect, game->mlx.img.data, game->scene.res.width);
}
