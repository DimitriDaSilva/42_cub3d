/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:29:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/22 17:19:56 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ftoa1.h"

/*
** Converts a float to a string
** @param:	- [float] nb to convert
**			- [int] nb of digits after the decimal point
** @return:	[char *] string formatted float number
** Line-by-line comments:
** @11-12	Checking if number beyond precision is >= 5 and rounding if needed
**			We only do the check if the number is not limit because in round
**			after decimal we need to multiply the number by 10 to get the next
**			fractional number
*/

char		*ft_ftoa(long double nb, int precision)
{
	int		length;
	char	*str_nb;

	length = get_length(nb, precision);
	str_nb = ft_calloc(length + 1, sizeof(char));
	if (!str_nb)
		return (0);
	get_integral_part(&str_nb, nb, precision, length);
	if (precision > 0)
		get_fractional_part(&str_nb, &nb, precision, length);
	if (!(nb == LONG_MIN || nb >= LONG_MAX))
		str_nb = round_after_decimal(nb, length, str_nb);
	return (str_nb);
}

/*
** Get the length of float based on the number and on the precision
** @param:	- [long double] floating point number
**			- [int] number of digits after decimal point to output
** @return:	[int] length of the string that will receive the float
** Line-by-line comments:
** @4		Length of integral part + decimal point + nb of digits
**			to put after the comma
** @6		If precision == 0, then the length of the integral part is enough
*/

static int	get_length(long double nb, int precision)
{
	int	len;

	if (precision > 0)
		len = get_len_float(nb) + 1 + precision;
	else
		len = get_len_float(nb);
	return (len);
}

/*
** Exctracts the integral part of a float into a string
** @param:	- [char **] string with preallocated space to receive the int part
**			- [long double] the floating point number
**			- [int] nb of digits after the decimal point
**			- [int] length of the number (with int + point + fractional)
** Line-by-line comments:
** @3-4		Edge case: the LONG_MAX number overflows right into ft_itoa().
**			It doesn't like the implicit casting long double to long long
**			As for why >=, he doesn't seem to be exactly equal to LONG_MAX
** @7-11	Edge case: negative numbers bellow -1 are considered 0 by ft_itoa
**			1 / nb < 0 takes into account number really close to 0
*/

static void	get_integral_part(char **str_nb,
		long double nb,
		int precision,
		int length)
{
	char	*tmp;

	if (nb >= LONG_MAX)
		tmp = ft_strdup("9223372036854775808");
	else
		tmp = ft_itoa(nb);
	if (-1 < nb && 1 / nb < 0)
	{
		**str_nb = '-';
		ft_strlcpy(*(str_nb) + 1, tmp, length - precision + 1);
	}
	else
		ft_strlcpy(*str_nb, tmp, length - precision + 1);
	free(tmp);
}

/*
** Extract the fractional part of
** @param:	- [type] param_value
**			- [type] param_value
** @return:	[type] return_value
** Line-by-line comments:
** @4-5		Edge cases:
**			- Multiplying by 10 LONG_MIN and LONG_MAX overflows
**			- The floating number only has 0s in the fractional part
** @6-10	Moving the decimal point to the right and extracting the digits
**			number
*/

static void	get_fractional_part(char **str_nb,
		long double *nb,
		int precision,
		int length)
{
	(*str_nb)[length - 1 - precision] = '.';
	while (precision-- > 0)
	{
		if (*nb == LONG_MIN || *nb >= LONG_MAX || ft_remainder(*nb, 1) == 0)
			(*str_nb)[length - 1 - precision] = '0';
		else
		{
			*nb *= 10;
			(*str_nb)[length - 1 - precision] = ft_abs(*nb) % 10 + '0';
		}
	}
}

/*
** Based on the remainder of nb, it will round the values
** @param:	- [double] value to be converted into string
**			- [int] total length of the number (sign incl.)
**			- [char *] string formatted float
** @return:	[char *] either the same or a new string (in case the rounding
**                   leads to an additional digit)
** Line-by-line comments:
** @4		In this function, we traverse the string/number from right to left
**			to be able to increment when necessary. -2 for '.' and for NULL
** @5		We need the nb and a remainder to access the value positioned in
**			index [length + 1]
** @8-15	Case: if last number is not 9 then the round will only take place
**			in the last digit. We can return after that case
** @10-11	Case: if the last displayed number is not a 9 and the remainder is
**			equal to 5, we apply the bankers rounding rule (aka round to even)
** @12-13	Case: if the last displayed number is not a 9 and the remainder is
**			above 5, we apply the standard rounding rule
** @16-17	Case: the last number is a 9 and is incremented to '0'. We use
**			while loop because it can generate a cascade of rounding
** @18-19	Case: we just incremented a 9 to a 0 so we need to round up one
**			more number. We need to make sure we are not changing the '.' and
**			that we actually moved in the string/number
** @20-21	Case: numbers that got successive bumping from 9 to 0 which
**			reached '.' AND numbers without decimal point but with a
**			remainder >= 5
*/

static char	*round_after_decimal(long double nb, int length, char *str_nb)
{
	long double	remainder;
	int			i;

	i = length - 1;
	remainder = ft_remainder(nb * 10, 10);
	if (remainder < 5)
		return (str_nb);
	if (str_nb[i] != '9')
	{
		if (remainder == 5 && !ft_is_even(str_nb[i]))
			str_nb[i] += 1;
		else if (5 < remainder)
			str_nb[i] += 1;
		return (str_nb);
	}
	while (str_nb[i] == '9' && ft_strchr(str_nb, '.'))
		str_nb[i--] = '0';
	if (ft_isdigit(str_nb[i]) && str_nb[i] != '9' && ft_strchr(str_nb, '.'))
		str_nb[i] += 1;
	else
		str_nb = round_before_decimal(str_nb, length);
	return (str_nb);
}
