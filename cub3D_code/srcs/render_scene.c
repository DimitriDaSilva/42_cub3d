/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:39:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"

void	render_scene(t_game *game)
{
	create_window(&game->mlx, &game->scene.res);
	mlx_loop_hook(game->mlx.mlx_ptr, render_next_frame, game);
	mlx_loop(game->mlx.mlx_ptr);
}
