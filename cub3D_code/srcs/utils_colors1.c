/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:58:57 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 09:55:41 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int		get_a(int argb)
{
	return (argb & (0xFF << 24));
}

int		get_r(int argb)
{
	return (argb & (0xFF << 16));
}

int		get_g(int argb)
{
	return (argb & (0xFF << 8));
}

int		get_b(int argb)
{
	return (argb & 0xFF);
}
