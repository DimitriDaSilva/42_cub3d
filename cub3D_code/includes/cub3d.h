/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:33:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 23:56:50 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** Forbiddent external libraries to delete
*/

# include <string.h>
# include <stdio.h>

/*
** External libraries
*/

# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>

/*
** Static libraries
*/

# include "../../libft/includes/libft.h"
# include "../../libmlx/mlx.h"

/*
** Header files
*/

# include "structs.h"
# include "constants.h"
# include "utils_others.h"
# include "utils_graph.h"
# include "utils_rays.h"
# include "utils_colors.h"

void	get_scene(int fd, t_scene *scene);
void	check_scene(t_scene *scene);
void	render_game(t_game *game);

#endif
