/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 12:26:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_screenshot.h"

/*
** Gets the first frame of the game and saves it in bmp format at the root
** of the directory. It creates an image, updates it once, draws it once, saves
** it and then exits
** @param:	- [t_game *] root struct
*/

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
	exit(EXIT_SUCCESS);
}

/*
** Saves the mlx_img to a new bmp file
** @param:	- [t_game *] root struct
** Line-by-line comments:
** @9-10	Two part header of all bmp files
*/

void	save_image_in_bmp(t_game *game)
{
	int	fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
	{
		printf("Error\nCould not create file screenshot.bmp.\n");
		exit(EXIT_SUCCESS);
	}
	write_bmp_header(game, fd);
	write_dib_header(game, fd);
	write_body(game, fd);
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file screenshot.bmp.\n");
		exit(EXIT_SUCCESS);
	}
}

/*
** Writes the first bmp header
** @param:	- [t_game *] root struct
**			- [int] file descripter to write in the new file created
** Line-by-line comments:
** @4		54 because the size of the first header is 14 bytes and the second
**			is 40 (14 + 40 = 54)
** @8		Writing all at once DOES NOT WORK. C structs seems to have
**			performance related features that bugs it. Basically it will add
**			round to 4 the bytes per field (so he'll assume the byte_signature
**			is 4 bytes offsetting all the rest of the header)
*/

void	write_bmp_header(t_game *game, int fd)
{
	t_bmp_header	bmp_header;
	int				ret;

	ft_strncpy(bmp_header.byte_signature, "BM", 2);
	bmp_header.size = 54 + game->scene.res.width * game->scene.res.height
		* (game->mlx.img.bpp / 8);
	bmp_header.reserved_bytes = 0;
	bmp_header.byte_offset = 14 + 40;
	ret = write(fd, &bmp_header.byte_signature, 2);
	ret = write(fd, &bmp_header.size, 4);
	ret = write(fd, &bmp_header.reserved_bytes, 4);
	ret = write(fd, &bmp_header.byte_offset, 4);
	(void)ret;
}

/*
** Writes the second header
** @param:	- [t_game *] root struct
**			- [int] file descripter to write in the new file created
** Line-by-line comments:
** @6			Bitmap files are written with upside down data for performance
**				reasons
** @10-11		Source: Google. Explanation: NOT worth the effort
*/

void	write_dib_header(t_game *game, int fd)
{
	t_dib_header	dib_header;
	int				ret;

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
	ret = write(fd, &dib_header.dib_header_size, 4);
	ret = write(fd, &dib_header.width, 4);
	ret = write(fd, &dib_header.height, 4);
	ret = write(fd, &dib_header.number_color_planes, 2);
	ret = write(fd, &dib_header.bpp, 2);
	ret = write(fd, &dib_header.compression_method, 4);
	ret = write(fd, &dib_header.raw_bitmap_data_size, 4);
	ret = write(fd, &dib_header.horizontal_resolution, 4);
	ret = write(fd, &dib_header.vertical_resolution, 4);
	ret = write(fd, &dib_header.color_table, 4);
	ret = write(fd, &dib_header.important_colors, 4);
	(void)ret;
}

/*
** Writes the pixels from the image into the bmp file. Bmp files have pixels
** stored upside down so we'll need to create an upside down array from the
** array of int we got from mlx
** @param:	- [t_game *] root struct
**			- [int] file descripter to write in the new file created
** Line-by-line comments:
** @6-7		An int is 4 bytes while a char is 1. Each char will have a value
**			between 0 and 255
** @16-19	Bitwise manipulation to get the colors in reverse from ARGB
**			hence in line 16 we get blue, 17 green etc.
*/

void	write_body(t_game *game, int fd)
{
	size_t	size;
	int		i;
	int		j;
	char	*pixel_arr;
	int		ret;

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
	ret = write(fd, pixel_arr, size * 4);
	free(pixel_arr);
	(void)ret;
}
