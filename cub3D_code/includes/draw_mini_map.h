/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:46 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 18:47:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MINI_MAP_H
# define DRAW_MINI_MAP_H

# include "cub3d.h"

void	draw_map(t_game *game);
void	draw_player(t_game *game);
int		get_fill_color(char grid_item);

#endif
