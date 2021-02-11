/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:06:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 18:48:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_GAME_H
# define RENDER_GAME_H

# include "cub3d.h"

void	render_game(t_game *game);
int		render_next_frame(void *my_struct);
void	save_bmp_img(t_game *game);

#endif

