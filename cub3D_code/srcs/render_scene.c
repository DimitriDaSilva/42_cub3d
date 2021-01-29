/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/29 12:41:46 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"

void	render_scene(void)
{
	t_mlx	mlx;
	int		count_h;
	int		count_w;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr,
											&mlx.img.bpp,
											&mlx.img.size_l,
											&mlx.img.endian);
	count_h = -1;
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if (count_w % 5)
				mlx.img.data[count_h * WIN_WIDTH + count_w] = get_opposite(0x00B4C639);
			else
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0x00B4C639;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

int		close_window(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	ft_printf("%d\n", keycode);
	return (1);
}
