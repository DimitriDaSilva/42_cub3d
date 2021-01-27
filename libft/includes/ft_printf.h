/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:40:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/23 17:04:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "ft_printf_types.h"
# include "ft_printf_utils.h"

va_list	g_arg_list;
int		g_count_printed_ch;

void	convert(const char **fmt);
void	get_settings(const char **fmt, t_format *settings);

#endif
