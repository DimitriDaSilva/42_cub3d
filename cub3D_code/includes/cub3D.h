/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:29:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/28 19:07:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct	s_img {
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

typedef struct	s_scene
{
	int			resolution[2];
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*sprite_texture;
	int			floor_color[3];
	int			ceilling_color[3];
	int			**map;
}				t_scene;

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../../libft/includes/libft.h"
# include "../../libmlx/mlx.h"
# include "utils_colors.h"


void	get_scene(int fd, t_scene *scene);
void	is_file_valid(char *file);
void	render_scene(void);
void	free_scene(t_scene *scene);

#endif
