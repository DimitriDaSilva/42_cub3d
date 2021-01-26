/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:29:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/26 19:26:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct  s_img {
    void        *img_ptr;
    char        *data;
    int         bpp;
    int         size_l;
    int         endian;
}               t_img;

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../../libft/includes/libft.h"
# include "../../libmlx/mlx.h"
# include "utils_colors.h"


int		is_file_valid(char *file);
void	render_game(void);

#endif
