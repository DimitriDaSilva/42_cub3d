/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:33:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 20:44:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define VALID_CHARS "012NSEW "
# define TILE_SIZE 30
# define PIXEL_OFFSET 10

/*
** Keycodes
*/
# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100

/*
** X11 Events
*/
# define CLIENT_MESSAGE 33
# define KEY_PRESS 02
# define KEY_RELEASE 03

/*
** X11 Masks
*/
# define NO_MASK 0L
# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1

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
# include "utils_graph.h"

void	get_scene(int fd, t_scene *scene);
void	check_scene(t_scene *scene, char *file);
void	init_player(t_player *player, char **grid);
void	render_game(t_game *game);

#endif
