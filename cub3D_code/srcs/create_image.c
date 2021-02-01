/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:28:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/01 19:47:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_image.h"

int		render_next_frame(void *my_struct)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	mlx = my_struct;
	create_new_image(mlx);
	i = -1;
	while (++i < mlx->scene->map_height * 32)
	{
		j = -1;
		while (++j < mlx->scene->map_width * 32)
		{
			int tilei = i / TILE_SIZE;
			int tilej = j / TILE_SIZE;
			if ((i % 32 == 0 || j % 32 == 0) && mlx->scene->map[tilei][tilej] != ' ')
				mlx->img.data[i * mlx->scene->resolution[0] + j] = 0x0014213d;
			else if (mlx->scene->map[tilei][tilej] == '1')
				mlx->img.data[i * mlx->scene->resolution[0] + j] = 0x0014213d;
			else if (mlx->scene->map[tilei][tilej] == '0')
				mlx->img.data[i * mlx->scene->resolution[0] + j] = 0x00FFFFFF;
			else if (mlx->scene->map[tilei][tilej] == ' ')
				mlx->img.data[i * mlx->scene->resolution[0] + j] = 0x00e5e5e5;
			else if (mlx->scene->map[tilei][tilej] == '2')
				mlx->img.data[i * mlx->scene->resolution[0] + j] = 0x00fca311;
			else if (mlx->scene->map[tilei][tilej] == 'N')
				mlx->img.data[i * mlx->scene->resolution[0] + j] = 0x0081b29a;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	return (1);
}

void	create_new_image(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->scene->resolution[0], mlx->scene->resolution[1]);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
											&mlx->img.bpp,
											&mlx->img.size_l,
											&mlx->img.endian);
}
