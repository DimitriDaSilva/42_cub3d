/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:06:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/05 20:35:52 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_GAME_H
# define RENDER_GAME_H

# include "cub3d.h"

void	create_window(t_game *game);
void	set_event_hooks(t_game *game);
int		render_next_frame(void *my_struct);
void	get_empty_img(t_mlx *mlx, t_res *res);
void	update(t_game *game);
void	draw_floor(t_game *game);
void	draw_ceilling(t_game *game);
void	draw_walls(t_game *game);
void	draw_sprites(t_game *game);
void	draw_mini_map(t_game *game);

#endif

