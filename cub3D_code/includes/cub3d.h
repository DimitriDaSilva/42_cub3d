/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:33:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 16:57:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define VALID_CHARS "012NSEW "
# define TILE_SIZE 30
# define PIXEL_OFFSET 10

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
