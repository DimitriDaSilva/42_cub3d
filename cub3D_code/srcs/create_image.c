/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:28:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:43:16 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_image.h"

int		render_next_frame(void *my_struct)
{
	t_game	*game;
	int		i;
	int		j;

	game = my_struct;
	create_new_image(&game->mlx, &game->scene.res);
	i = -1;
	while (++i < game->scene.map.height * 32)
	{
		j = -1;
		while (++j < game->scene.map.width * 32)
		{
			int tilei = i / TILE_SIZE;
			int tilej = j / TILE_SIZE;
			if ((i % 32 == 0 || j % 32 == 0) && game->scene.map.grid[tilei][tilej] != ' ')
				game->mlx.img.data[i * game->scene.res.width + j] = 0x0014213d;
			else if (game->scene.map.grid[tilei][tilej] == '1')
				game->mlx.img.data[i * game->scene.res.width + j] = 0x0014213d;
			else if (game->scene.map.grid[tilei][tilej] == '0')
				game->mlx.img.data[i * game->scene.res.width + j] = 0x00FFFFFF;
			else if (game->scene.map.grid[tilei][tilej] == ' ')
				game->mlx.img.data[i * game->scene.res.width + j] = 0x00e5e5e5;
			else if (game->scene.map.grid[tilei][tilej] == '2')
				game->mlx.img.data[i * game->scene.res.width + j] = 0x00fca311;
			else if (game->scene.map.grid[tilei][tilej] == 'N')
				game->mlx.img.data[i * game->scene.res.width + j] = 0x0081b29a;
		}
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.img_ptr);
	return (1);
}

void	create_new_image(t_mlx *mlx, t_res *res)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, res->width, res->height);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
											&mlx->img.bpp,
											&mlx->img.size_l,
											&mlx->img.endian);
}
