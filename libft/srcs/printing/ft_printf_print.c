/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:29:52 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 10:42:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print.h"

/*
** Strings to print according to flags
** @param:	- [char *] correctly formatted string to print
** 			- [t_format] all 5 fields: flags, width, precision, size, type
*/

void		print_left_right(t_format *settings, char *str)
{
	if (ft_strchr(settings->flags, '-'))
		print_left(str, settings);
	else
		print_right(str, settings);
}

/*
** If flag == '-' and width >= 0, the printed value is left aligned
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
**			- [char] when left aligned, no padding is inserted on the right
**                   of the printed value so here the padding is
**                   always a space. So it could be a constant but to
**                   keep the design pattern consistent, it's like that
** @return:	[int] number of printed characters
** Line-by-line comments:
** @1		Unlike everywhere else in this function, we need a local count
**			of char printed to adjust the number of spaces printed
** @4-5		Edge case: for an arg NULL char, the putstr doesn't print anything
**			Function requirements ask for a ^@ to be printed
** @6-8		Edge case: for duixX, if precision == 0 && nb = 0, nothing to print
**			We are printing all cases that do not verify this edge case
** @9		Width needs to take into account already printed characters
** @10-12	Printing width times a space
*/

static void	print_left(char *str, t_format *settings)
{
	int		count_printed_ch;

	count_printed_ch = 0;
	if (settings->type == 'c' && *str == 0)
		count_printed_ch += ft_putchar(0);
	else if (!ft_strchr("duixX", settings->type) ||
			!(*str == '0' && settings->precision == 0))
		count_printed_ch += ft_putstr(str);
	settings->width -= count_printed_ch;
	while (settings->width-- > 0)
		count_printed_ch += ft_putchar(' ');
	g_count_printed_ch += count_printed_ch;
}

/*
** If there is no flag used or flag == '0' and width >= 0, the printed value
** is right aligned. Padded with '0' if '0' flag, otherwise with spaces
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
**			- [char] either '0' or ' ' depending on the flag and the type
**					as char and string can't be printed with the '0' flag
** @return:	[int] number of printed characters
** Line-by-line comments:
** @1-2		Edge case: when the char is 0 it still needs to print ^@ but
**			it isn't being accounted for on line 14
** @3-5		Edge case: for duixX, if precision == 0 && nb = 0, nothing to print
**			But the '0' is still being accounted for
** @6		Width needs to take into account already printed characters
** @7		We need to make sure we are making space for the str to print
** @8-9	Printing width times a space
** @10-11	Edge case: for an arg NULL char, the putstr doesn't print anything
**			Function requirements ask for a ^@ to be printed
** @12-13	Edge case: for duixX, if precision == 0 && nb = 0, nothing to print
**			We are printing all cases that do not verify this edge case
*/

static void	print_right(char *str, t_format *settings)
{
	if (settings->type == 'c' && *str == 0)
		settings->width--;
	else if (ft_strchr("duixX", settings->type) && *str == '0' &&
			settings->precision == 0)
		settings->width++;
	settings->width -= ft_strlen(str);
	while (settings->width-- > 0)
		g_count_printed_ch += ft_putchar(' ');
	if (settings->type == 'c' && *str == 0)
		g_count_printed_ch += ft_putchar(0);
	else if (!ft_strchr("duixX", settings->type) ||
			!(*str == '0' && settings->precision == 0))
		g_count_printed_ch += ft_putstr(str);
}
