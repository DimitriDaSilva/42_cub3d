/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 08:53:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_screenshot.h"

void	get_screenshot(t_game *game)
{
	game->mlx.img.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
										game->scene.res.width,
										game->scene.res.height);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.img_ptr,
												&game->mlx.img.bpp,
												&game->mlx.img.size_l,
												&game->mlx.img.endian);
	update(game);
	draw(game);
	save_image_in_bmp(game);
}

void	save_image_in_bmp(t_game *game)
{
	int	fd;
	
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_printf("Error\nCould not create file screenshot.bmp.\n");
		exit(EXIT_SUCCESS);
	}
	write_bmp_header(game, fd);
	write_dib_header(game, fd);
	write_body(game, fd);
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close file screenshot.bmp.\n");
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
}

void	write_bmp_header(t_game *game, int fd)
{
	t_bmp_header	bmp_header;

	ft_strncpy(bmp_header.byte_signature, "BM", 2);
	bmp_header.size = 54 + game->scene.res.width * game->scene.res.height
					* (game->mlx.img.bpp / 8);
	bmp_header.reserved_bytes = 0;
	bmp_header.byte_offset = 14 + 40;
	write(fd, &bmp_header.byte_signature, 2);
	write(fd, &bmp_header.size, 4);
	write(fd, &bmp_header.reserved_bytes, 4);
	write(fd, &bmp_header.byte_offset, 4);
}

void	write_dib_header(t_game *game, int fd)
{
	t_dib_header	dib_header;

	dib_header.dib_header_size = 40;
	dib_header.width = game->scene.res.width;
	dib_header.height = -game->scene.res.height;
	dib_header.number_color_planes = 1;
	dib_header.bpp = game->mlx.img.bpp;
	dib_header.compression_method = 0;
	dib_header.raw_bitmap_data_size = 0;
	dib_header.horizontal_resolution = 2835;
	dib_header.vertical_resolution = 2835;
	dib_header.color_table = 0;
	dib_header.important_colors = 0;
	write(fd, &dib_header.dib_header_size, 4);
	write(fd, &dib_header.width, 4);
	write(fd, &dib_header.height, 4);
	write(fd, &dib_header.number_color_planes, 2);
	write(fd, &dib_header.bpp, 2);
	write(fd, &dib_header.compression_method, 4);
	write(fd, &dib_header.raw_bitmap_data_size, 4);
	write(fd, &dib_header.horizontal_resolution, 4);
	write(fd, &dib_header.vertical_resolution, 4);
	write(fd, &dib_header.color_table, 4);
	write(fd, &dib_header.important_colors, 4);
}

void	write_body(t_game *game, int fd)
{
	size_t	size;
	int		i;
	int		j;
	char	*pixel_arr;
	
	size = game->scene.res.width * game->scene.res.height
							* (game->mlx.img.bpp / 8);
	pixel_arr = malloc(size * sizeof(char));
	if (!pixel_arr)
		exit(EXIT_SUCCESS);
	i = 0;
	j = 0;
	size /= 4;
	while (i < (int)size)
	{
		pixel_arr[j++] = game->mlx.img.data[i] & 255;
		pixel_arr[j++] = (game->mlx.img.data[i] & 255 << 8) >> 8;
		pixel_arr[j++] = (game->mlx.img.data[i] & 255 << 16) >> 16;
		pixel_arr[j++] = (game->mlx.img.data[i] & 255 << 24) >> 24;
		i++;
	}
	write(fd, pixel_arr, size * 4);
	free(pixel_arr);
}
