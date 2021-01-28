/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:53:42 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 11:03:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_types.h"

/*
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
** Line-by-line comments:
** @4		-1 means no precision as been specified. 6 is the default
** @6		If the flags # is used, if forces a decimal point (even if
**			precision == 0)
** @8-11	Adding the padding of '0' associated with the '0' flags. The 0s
**			go before the signs
** @12		Adding the padding of '0' associated with the fact that precision
**			would be higher than length of number (if so left-padded with 0)
*/

void	print_flt(t_format *settings)
{
	char	*nb_to_print;
	int		float_precision;

	float_precision = settings->precision <= -1 ? 6 : settings->precision;
	nb_to_print = ft_ftoa(va_arg(g_arg_list, double), float_precision);
	add_point(&nb_to_print, settings);
	add_sign(&nb_to_print, settings->flags);
	if (ft_strchr(settings->flags, '0') && ft_strchr("+- ", *nb_to_print))
		add_padding(&nb_to_print, settings->width - 1);
	else if (ft_strchr(settings->flags, '0'))
		add_padding(&nb_to_print, settings->width);
	add_padding(&nb_to_print, settings->precision);
	print_left_right(settings, nb_to_print);
	free(nb_to_print);
}

/*
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
** Line-by-line comments:
** @6		-1 means no precision as been specified. 6 is the default
** @8		We send both the addresses of nb and exponent so that the function
**			can change the number as it's figuring out the exponent. It also
**			stores in exponent the exponent formatted
**			string "[sign][double-digit number]" (i.e. "+01")
** @9		Once we got our number with the right decimal point placement,
**			we can convert it from float to string
** @10		If the flags # is used, if forces a decimal point (even if
**			precision == 0)
** @11		Concat of float formatted string + 'e' + exponent
** @12		In some rounding edge cases, I add "10.0e+01". This function
**			removes the '0' from the integral part and increments the
**			exponent
** @13		Adds '+' or ' ' if one or both flags are used (if both are
**			' ' flag is to be ignored)
** @14-17	Adding the padding of '0' associated with the '0' flags. The 0s
**			go before the signs
** @18		Adding the padding of '0' associated with the fact that precision
**			would be higher than length of number (if so left-padded with 0)
*/

void	print_exp(t_format *settings)
{
	char	*nb_to_print;
	int		float_precision;
	char	*exponent;
	double	nb;

	float_precision = settings->precision <= -1 ? 6 : settings->precision;
	nb = va_arg(g_arg_list, double);
	get_exp_str(&nb, &exponent);
	nb_to_print = ft_ftoa(nb, float_precision);
	add_point(&nb_to_print, settings);
	add_exponent(&nb_to_print, &exponent);
	adjust_rounding(nb_to_print);
	add_sign(&nb_to_print, settings->flags);
	if (ft_strchr(settings->flags, '0') && ft_strchr("+- ", *nb_to_print))
		add_padding(&nb_to_print, settings->width - 1);
	else if (ft_strchr(settings->flags, '0'))
		add_padding(&nb_to_print, settings->width);
	add_padding(&nb_to_print, settings->precision);
	print_left_right(settings, nb_to_print);
	free(nb_to_print);
}

/*
** Check the exponent and the precision and based on those values prints on
** either float format or exponent. %g basically takes a value and finds the
** most compact format. The float and scientific notation formats aren't
** exactly the same as previously: all trailing zeros (for float) or middle
** zeros (for sci-notation) are removed and there is no padding related to
** precision being higher than length of number
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
** Line-by-line comments:
** @8-9		Unlike elsewhere in this function, if precision flag indicated 0, we
**			need to consider it's 1
*/

void	print_g(t_format *settings)
{
	double	nb;
	int		exponent;
	int		actual_precision;

	nb = va_arg(g_arg_list, double);
	exponent = get_exp_nb(nb);
	actual_precision = settings->precision <= -1 ? 6 : settings->precision;
	if (settings->precision == 0)
		actual_precision = 1;
	if (-4 <= exponent && exponent < actual_precision)
		print_g_flt(settings, nb, actual_precision - 1 - exponent);
	else
		print_g_exp(settings, nb, actual_precision - 1);
}

/*
** Float format with trailing zeros truncated
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
**			- [double] argument passed as ft_printf variadic argument with no
**                     modification did to it
**			- [int] Unlike elsewhere in this function, precision means the
**					number of significant numbers to display (not the number
**					of digits after the decimal point)
** Line-by-line comments:
** @3-4		If the number rounds up to 1, we need to display one extra
**			significant number
** @6-7		The flag # forces the trailing zeros to remain
** @8		If the flags # is used, if forces a decimal point (even if
**			precision == 0)
** @9		Adds '+' or ' ' if one or both flags are used (if both are
**			' ' flag is to be ignored)
** @10-13	Adding the padding of '0' associated with the '0' flags. The 0s
**			go before the signs
*/

void	print_g_flt(t_format *settings, double nb, int precision)
{
	char	*nb_to_print;

	if (0.9 < ft_abs_dl(nb) && ft_abs_dl(nb) < 1)
		precision++;
	nb_to_print = ft_ftoa(nb, precision);
	if (!ft_strchr(settings->flags, '#'))
		remove_trailing_zero(nb_to_print);
	add_point(&nb_to_print, settings);
	add_sign(&nb_to_print, settings->flags);
	if (ft_strchr(settings->flags, '0') && ft_strchr("+- ", *nb_to_print))
		add_padding(&nb_to_print, settings->width - 1);
	else if (ft_strchr(settings->flags, '0'))
		add_padding(&nb_to_print, settings->width);
	print_left_right(settings, nb_to_print);
	free(nb_to_print);
}

/*
** Scientific notation format with middle zeros truncated
** @param:	- [t_format] all 5 fields: flags, width, precision, size, type
**			- [double] argument passed as ft_printf variadic argument with no
**                     modification did to it
**			- [int] Unlike elsewhere in this function, precision means the
**					number of significant numbers to display (not the number
**					of digits after the decimal point)
** Line-by-line comments:
** @4		We send both the addresses of nb and exponent so that the function
**			can change the number as it's figuring out the exponent. It also
**			stores in exponent the exponent formatted
**			string "[sign][double-digit number]" (i.e. "+01")
** @5		Once we got our number with the right decimal point placement,
**			we can convert it from float to string
** @6		If the flags # is used, if forces a decimal point (even if
**			precision == 0)
** @7		Concat of float formatted string + 'e' + exponent
** @8		In some rounding edge cases, I add "10.0e+01". This function
**			removes the '0' from the integral part and increments the
**			exponent
** @9-10	The flag # forces the trailing zeros to remain
** @11		Adds '+' or ' ' if one or both flags are used (if both are
**			' ' flag is to be ignored)
** @12-15	Adding the padding of '0' associated with the '0' flags. The 0s
**			go before the signs
*/

void	print_g_exp(t_format *settings, double nb, int precision)
{
	char	*nb_to_print;
	char	*exponent;

	get_exp_str(&nb, &exponent);
	nb_to_print = ft_ftoa(nb, precision);
	add_point(&nb_to_print, settings);
	add_exponent(&nb_to_print, &exponent);
	adjust_rounding(nb_to_print);
	if (!ft_strchr(settings->flags, '#'))
		remove_middle_zero(nb_to_print);
	add_sign(&nb_to_print, settings->flags);
	if (ft_strchr(settings->flags, '0') && ft_strchr("+- ", *nb_to_print))
		add_padding(&nb_to_print, settings->width - 1);
	else if (ft_strchr(settings->flags, '0'))
		add_padding(&nb_to_print, settings->width);
	print_left_right(settings, nb_to_print);
	free(nb_to_print);
}
