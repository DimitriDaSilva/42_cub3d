/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:30:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/03 19:32:09 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct	s_scene
{
	t_res		res;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sprite_texture;
	t_color		floor;
	t_color		ceilling;
	t_map		map;
	int			mini_map_tile_size;
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
	double		size;
	char		obstacle;
}				t_ray;

typedef struct	s_rays
{
	int			total_rays;
	t_ray		*arr;
}				t_rays;

typedef struct	s_game
{
	t_mlx		mlx;
	t_scene		scene;
	t_player	player;
	t_rays		rays;
}				t_game;

/*
** Structs used by utils_graph
*/
typedef struct	s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		fill_color;
	int		border_color;
	int		border_width;
}				t_rect;

typedef struct s_circle
{
	int		x;
	int		y;
	double	radius;
	int		fill_color;
	int		border_color;
	int		border_width;
}				t_circle;

typedef struct s_line
{
	int		begin_x;
	int		begin_y;
	int		end_x;
	int		end_y;
	int		color;
	int		width;
}				t_line;

#endif
