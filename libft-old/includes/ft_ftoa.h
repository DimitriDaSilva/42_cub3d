/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:32:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/23 08:48:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FTOA_H
# define FT_FTOA_H

# include "libft.h"

static char		*round_after_decimal(double nb, int length, char *str_nb);
static char		*round_before_decimal(char *str_nb, int length);
static int		get_new_length(char *str_nb, int length);
static void		copy_after_decimal(char *str_nb,
									char *new_str_nb,
									int length,
									int new_length);

#endif
