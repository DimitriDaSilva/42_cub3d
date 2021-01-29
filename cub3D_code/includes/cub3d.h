/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:33:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/29 17:31:32 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

/*
** To delete
*/
# include <string.h>
# include <stdio.h>

/*
** To keep
*/
# include <fcntl.h>
# include <math.h>
# include "../../libft/includes/libft.h"
# include "../../libmlx/mlx.h"
# include "structs.h"
# include "utils.h"
# include "utils_colors.h"

void			get_scene(int fd, t_scene *scene);
void			print_scene(t_scene *scene);
void			is_scene_valid(t_scene *scene, char *file);
void			render_scene(void);
void			init_scene(t_scene *scene);

#endif
