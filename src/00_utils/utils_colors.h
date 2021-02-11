/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:59:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/11 00:36:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_COLORS_H
# define UTILS_COLORS_H

# include "cub3d.h"

int		create_argb(int a, int r, int g, int b);
int		get_a(int argb);
int		get_r(int argb);
int		get_g(int argb);
int		get_b(int argb);
int		add_shade(double distance, int color);
int		get_opposite(int color);

#endif
