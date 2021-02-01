/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/01 18:49:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"

void	render_scene(t_scene *scene)
{
	t_mlx	mlx;

	mlx.scene = scene;
	create_window(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, render_next_frame, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
