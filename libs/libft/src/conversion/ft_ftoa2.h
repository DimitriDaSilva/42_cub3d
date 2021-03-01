/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:32:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/21 21:01:22 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FTOA2_H
# define FT_FTOA2_H

# include "libft.h"

static int		get_new_length(char *str_nb, int length);
static void		copy_after_decimal(char *str_nb,
									char *new_str_nb,
									int length,
									int new_length);
static int		get_pos_dec_point_old_str(char *str_nb, int length_old_str);
static int		get_pos_dec_point_new_str(int index_old_str,
		int length,
		int new_length);

#endif
