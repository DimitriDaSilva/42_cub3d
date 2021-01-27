/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:47:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 10:42:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_types.h"

/*
** Functions created for spac... modularity purposes. It simply get the right
** arg type based on the size field
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
*/

void	print_int_signed(t_format *settings)
{
	char	*nb_to_print;

	if (!ft_strncmp(settings->size, "ll", 3))
		nb_to_print = ft_itoa(va_arg(g_arg_list, long long int));
	else if (!ft_strncmp(settings->size, "l", 2))
		nb_to_print = ft_itoa(va_arg(g_arg_list, long int));
	else
		nb_to_print = ft_itoa(va_arg(g_arg_list, int));
	print_int(settings, nb_to_print);
}

/*
** Functions created for spac... modularity purposes. It simply get the right
** arg type based on the size field
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
*/

void	print_int_unsigned(t_format *settings)
{
	char	*nb_to_print;

	if (!ft_strncmp(settings->size, "ll", 3))
		nb_to_print = ft_itoa(va_arg(g_arg_list, unsigned long long int));
	else if (!ft_strncmp(settings->size, "l", 2))
		nb_to_print = ft_itoa(va_arg(g_arg_list, unsigned long int));
	else
		nb_to_print = ft_itoa(va_arg(g_arg_list, unsigned int));
	print_int(settings, nb_to_print);
}

/*
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
**			- [char *] string formatted number to adjust and print
** Line-by-line comments:
** @1		Add sign ' ' or '+' based on the flag used
**			'-' sign is handled by ft_itoa()
** @2-5 	Adding the padding of '0' associated with the '0' flags. The 0s
**			go before the signs
** @6		Adding the padding of '0' associated with the fact that precision
**			would be higher than length of number (if so left-padded with 0)
** @7-8		Edge case: if precision == 0, nb = 0 and flag = '+', only the '+'
**			is printed
*/

void	print_int(t_format *settings, char *nb_to_print)
{
	add_sign(&nb_to_print, settings->flags);
	if (ft_strchr(settings->flags, '0') && ft_strchr("+- ", *nb_to_print))
		add_padding(&nb_to_print, settings->width - 1);
	else if (ft_strchr(settings->flags, '0'))
		add_padding(&nb_to_print, settings->width);
	add_padding(&nb_to_print, settings->precision);
	if (!ft_strncmp(nb_to_print, "+0", 3) && settings->precision == 0)
		nb_to_print[1] = '\0';
	print_left_right(settings, nb_to_print);
	free(nb_to_print);
}

/*
** The n specifier receives a pointer to an int as an arg. It puts number of
** printed char in this variable. The count doesn't restart between printing
** of each number or string
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
*/

void	print_n(t_format *settings)
{
	long long int	*nb;

	if (!ft_strncmp(settings->size, "ll", 3))
		nb = va_arg(g_arg_list, long long int *);
	else if (!ft_strncmp(settings->size, "l", 2))
		nb = (long long int *)va_arg(g_arg_list, long int *);
	else
		nb = (long long int *)va_arg(g_arg_list, int *);
	*nb = g_count_printed_ch;
}

/*
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
** @return:	[int] number of printed characters
*/

void	print_pct(t_format *settings)
{
	settings->width = 0;
	print_left_right(settings, "%");
}
