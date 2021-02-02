/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 08:49:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:21:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_window.h"

void	create_window(t_mlx *mlx, t_res *res)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, res->width, res->height, "Cub3d");
	mlx_key_hook(mlx->win, close_window_esc, mlx);
	mlx_hook(mlx->win, 33, 0L, close_window_cross, mlx);
}

int		close_window_esc(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (1);
}

int		close_window_cross(int keycode, t_mlx *mlx)
{
	(void)mlx;
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (1);
}
