/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa1.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:32:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/22 17:11:59 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FTOA1_H
# define FT_FTOA1_H

# include "libft.h"

static int	get_length(long double nb, int precision);
static void	get_integral_part(char **str_nb,
		long double nb,
		int precision,
		int length);
static void	get_fractional_part(char **str_nb,
		long double *nb,
		int precision,
		int length);
static char	*round_after_decimal(long double nb, int length, char *str_nb);
char		*round_before_decimal(char *str_nb, int length);

#endif
