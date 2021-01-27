/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:33:30 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/23 17:06:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINT_H
# define FT_PRINTF_PRINT_H

# include "ft_printf.h"

static void	print_left(char *str, t_format *settings);
static void	print_right(char *str, t_format *settings);

#endif
