/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:30:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 15:39:22 by dda-silv         ###   ########.fr       */
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
}				t_scene;

typedef struct	s_player
{
	double		x;
	double		y;
	double		radius;
	int			walk_direction;
	float		move_speed;
	int			turn_direction;
	double		rotation_angle;
	double		rotation_speed;
}				t_player;

typedef struct	s_game
{
	t_mlx		mlx;
	t_scene		scene;
	t_player	player;
}				t_game;

typedef struct	s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		fill_color;
	int		stroke_color;
	int		stroke_width;
}				t_rect;

#endif
