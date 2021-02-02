/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:44:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 16:44:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_graph.h"

void	draw_rect(t_rect *rect, int	*img, int res_width)
{
	int	i;
	int	j;

	rect->stroke_width--;
	i = -1;
	while (++i < rect->height)
	{
		j = -1;
		while (++j < rect->width)
		{
			if (i <= 0 + rect->stroke_width || j <= 0 + rect->stroke_width ||
				i >= rect->height - 1 - rect->stroke_width ||
				j >= rect->width - 1 - rect->stroke_width)
				img[(rect->y + i) * res_width + rect->x + j] = rect->stroke_color;
			else
				img[(rect->y + i) * res_width + rect->x + j] = rect->fill_color;
		}
	}
}
