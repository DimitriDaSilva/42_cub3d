/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 08:52:44 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/03 16:46:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_WINDOW_H
# define CREATE_WINDOW_H

# include "cub3d.h"

void	check_user_res(t_mlx *mlx, t_res *res);
void	set_mini_map_size(t_scene *scene);
void	set_rays(t_game *game);

#endif
