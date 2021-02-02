/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:46 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 16:51:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MINI_MAP_H
# define DRAW_MINI_MAP_H

# include "cub3d.h"

void	draw_rect(t_rect *rect, int	*img, int res_width);
int		get_fill_color(char grid_item);

#endif
