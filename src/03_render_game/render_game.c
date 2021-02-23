/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:57:03 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_game.h"

/*
** Function that renders the game. Called once the .cub is done being parsed
** for check and storing the params
** @param:	- [t_game *] root struct
** Line-by-line comments:
** @2-8		No need to create a window in save mode
** @9		Some scene preparations rely on having the mlx_ptr and the window
** @10-14	In PLAY mode, mlx_loop_hook calls one time per frame the function
**			render_next_frame
** @13		Ensures that the function only finishes if the user closes the
**			window
*/

void	render_game(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!ft_strcmp(game->mode, "PLAY"))
	{
		game->mlx.win = mlx_new_window(game->mlx.mlx_ptr,
				game->scene.res.width,
				game->scene.res.height,
				"Cub3d");
	}
	ready_game(game);
	if (!ft_strcmp(game->mode, "PLAY"))
	{
		mlx_loop_hook(game->mlx.mlx_ptr, render_next_frame, game);
		mlx_loop(game->mlx.mlx_ptr);
	}
	else if (!ft_strcmp(game->mode, "SAVE"))
	{
		get_screenshot(game);
	}
}

/*
** Function called once per frame to update, draw and put to screen the new
** image
** @param:	- [void *] the address of my root struct
** @return:	[int] irrelevant to us. Function passed by mlx_loop_hook has to
**				  return an int
*/

int		render_next_frame(void *my_struct)
{
	t_game	*game;

	game = my_struct;
	game->mlx.img.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
			game->scene.res.width,
			game->scene.res.height);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.img_ptr,
			&game->mlx.img.bpp,
			&game->mlx.img.size_l,
			&game->mlx.img.endian);
	update(game);
	draw(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr,
							game->mlx.win,
							game->mlx.img.img_ptr,
							0,
							0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.img_ptr);
	return (1);
}
