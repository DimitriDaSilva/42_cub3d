/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:46 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 21:52:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MINI_MAP_H
# define DRAW_MINI_MAP_H

# include "cub3d.h"

void	draw_map(t_game *game);
void	draw_player(t_game *game, double tile_size);
int		get_fill_color(t_color *floor_color, char grid_item);
void	draw_rays(t_game *game, double tile_size);

#endif
