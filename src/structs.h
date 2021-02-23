/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:30:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:35:46 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** General
*/

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_res
{
	int			width;
	int			height;
}				t_res;

typedef struct	s_texture
{
	char		*path;
	t_img		img;
	int			width;
	int			height;
}				t_texture;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			argb;
}				t_color;

typedef struct	s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct	s_sprite
{
	double		x;
	double		y;
	t_texture	*tex;
	double		distance;
	double		rotation_angle;
	int			is_visible;
}				t_sprite;

typedef struct	s_scene
{
	t_res		res;
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_texture	ea_tex;
	t_texture	sprite_tex;
	t_color		floor;
	t_color		ceilling;
	t_map		map;
	int			mini_map_tile_size;
	int			total_sprites;
	t_sprite	*sprites;
}				t_scene;

typedef struct	s_player
{
	double		x;
	double		y;
	double		radius;
	char		walk_direction;
	double		move_speed;
	int			turn_direction;
	double		rotation_angle;
	double		rotation_speed;
}				t_player;

typedef struct	s_ray
{
	double		x;
	double		y;
	double		size;
	char		obstacle;
	double		angle;
	char		orientation;
	char		side;
	double		x_step;
	double		y_step;
}				t_ray;

typedef struct	s_rays
{
	t_ray		*arr;
	double		view_angle;
	double		dist_proj_plane;
}				t_rays;

typedef struct	s_game
{
	t_mlx		mlx;
	t_scene		scene;
	t_player	player;
	t_rays		rays;
	char		mode[5];
}				t_game;

/*
** Graphical
*/

typedef struct	s_rect
{
	int			x;
	int			y;
	double		width;
	double		height;
	int			fill_color;
	int			border_color;
	int			border_width;
	t_texture	tex;
	t_sprite	*sprite;
}				t_rect;

typedef struct	s_circle
{
	int			x;
	int			y;
	double		radius;
	int			fill_color;
	int			border_color;
	int			border_width;
}				t_circle;

typedef struct	s_line
{
	int			begin_x;
	int			begin_y;
	int			end_x;
	int			end_y;
	int			color;
	int			width;
}				t_line;

/*
** BPM file creator
*/

typedef struct	s_bmp_header
{
	char		byte_signature[2];
	uint32_t	size;
	uint32_t	reserved_bytes;
	uint32_t	byte_offset;
}				t_bmp_header;

typedef struct	s_dib_header
{
	uint32_t	dib_header_size;
	int32_t		width;
	int32_t		height;
	uint16_t	number_color_planes;
	uint16_t	bpp;
	uint32_t	compression_method;
	uint32_t	raw_bitmap_data_size;
	int32_t		horizontal_resolution;
	int32_t		vertical_resolution;
	uint32_t	color_table;
	uint32_t	important_colors;
}				t_dib_header;

#endif
