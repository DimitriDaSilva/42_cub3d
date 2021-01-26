/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:18:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/26 19:41:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_game(void)
{
	void	*mlx;
	t_img	img;

	mlx = mlx_init();
	img.img_ptr = mlx_new_image(mlx, 500, 400);
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

}
