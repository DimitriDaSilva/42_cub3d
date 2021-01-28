/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:47:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 09:02:48 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Implementation of printf. All subsequent functions return the number of
** printed characters
** Besides ft_printf_utils, the files follow a logical order:
** ft_printf > ft_printf_settings > ft_printf_types1 > ft_printf_types2
** @param:	- [const char *] string inputted with specified formats
**			- [...] variadic arguments that refer to the specifiied formatj
** @return:	[int] number of printed characters
** Line-by-line comments:
** @6		The address of fmt is passed so that subsequent functions can
** 			increment through the fmt string
** @9		When finding a format specifier like %-10d, the subsequent
** 			functions increment through "%-10" while here 'd' is incremented
*/

int		ft_printf(const char *fmt, ...)
{
	g_count_printed_ch = 0;
	va_start(g_arg_list, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			convert(&fmt);
		else
			g_count_printed_ch += ft_putchar(*fmt);
		fmt++;
	}
	va_end(g_arg_list);
	return (g_count_printed_ch);
}

/*
** Traverses fmt to get the settings and prints the output
** @param:	- [const char *] string inputted with specified formats
*/

void	convert(const char **fmt)
{
	t_format	settings;

	(*fmt)++;
	get_settings(fmt, &settings);
	print_types(&settings);
}
