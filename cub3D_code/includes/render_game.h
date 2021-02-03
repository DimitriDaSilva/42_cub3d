/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:06:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/03 12:55:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_GAME_H
# define RENDER_GAME_H

# include "cub3d.h"

void	create_window(t_mlx *mlx, t_scene *scene);
void	set_event_hooks(t_game *game);
int		render_next_frame(void *my_struct);
void	get_empty_img(t_mlx *mlx, t_res *res);
void	update(t_game *game);
void	draw_mini_map(t_game *game);
void	draw_background(t_game *game);

#endif

