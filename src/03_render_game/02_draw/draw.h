/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:58:59 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:31:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

void	draw_floor(t_game *game);
void	draw_ceilling(t_game *game);
void	draw_walls(t_game *game);
void	draw_sprites(t_game *game);
void	draw_mini_map(t_game *game);

#endif
