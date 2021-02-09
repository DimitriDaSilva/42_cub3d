/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:33:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/08 16:17:46 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define VALID_CHARS "012NSEW "
# define MINIMAP_RATIO 50
// # define MINIMAP_RATIO 200
# define MINIMAP_OFFSET 10
# define SCALE 64
# define VIEW_ANGLE 60

/*
** Keycodes
*/
# define K_ESC 65307
# define K_W 122
# define K_A 113
# define K_S 115
# define K_D 100
# define K_LEFT_ARROW 65361
# define K_RIGHT_ARROW 65363

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
# include <X11/Xlib.h>
# include "../../libft/includes/libft.h"
# include "../../libmlx/mlx.h"
# include "structs.h"
# include "utils.h"
# include "utils_colors.h"
# include "utils_graph.h"
# include "utils_rays1.h"
# include "utils_rays2.h"

void	get_scene(int fd, t_scene *scene);
void	check_scene(t_scene *scene, char *file);
void	init_player(t_player *player, t_scene *scene);
void	render_game(t_game *game);

#endif
