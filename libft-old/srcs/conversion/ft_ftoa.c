/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:29:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/24 20:42:26 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ftoa.h"

/*
** Converts a float to a string
** @param:	- [float] nb to convert
**			- [int] nb of digits after the decimal point
** @return:	[char *] string formatted float number
** Line-by-line comments:
** @5		Size = length of decimal number + decimal point + nb of digits
**			to put after the comma
** @8-16	Extracting the number before decimal point
** @9-13	Edge case: negative numbers bellow -1 are considered 0 by ft_itoa
**			1 / nb < 0 takes into account number really close to 0
** @19-20	Extracting the number after decimal point
** @21		Checking if number beyond precision is >= 5 and rounding if needed
*/

char			*ft_ftoa(double nb, int precision)
{
	int		length;
	char	*str_nb;
	char	*tmp;

	length = precision > 0 ? get_size_dl(nb) + 1 + precision : get_size_dl(nb);
	if (!(str_nb = calloc(length + 1, sizeof(char))))
		return (0);
	tmp = ft_itoa(nb);
	if (-1 < nb && 1 / nb < 0)
	{
		*str_nb = '-';
		ft_strlcpy(str_nb + 1, tmp, length - precision + 1);
	}
	else
		ft_strlcpy(str_nb, tmp, length - precision + 1);
	free(tmp);
	if (precision > 0)
		str_nb[length - 1 - precision] = '.';
	while (precision-- > 0)
		str_nb[length - 1 - precision] = ft_abs_lg(nb *= 10) % 10 + '0';
	str_nb = round_after_decimal(nb, length, str_nb);
	return (str_nb);
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

static char		*round_after_decimal(double nb, int length, char *str_nb)
{
	double	remainder;
	int		i;

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

/*
** If function called, after rounding up, the digits before the breakpoint
** need to also be rounded up. Possibly with an extra digit
** @param:	- [char *] string formatted float
**			- [int] total length of the number (sign incl.)
** @return:	[char *] new str with either the same number of chars or with
**                   an extra char (i.e. 99 -> 100)
** Line-by-line comments:
** @3		i = old string index
** @4		j = new string index
** @9		Finding the index of the decimal point by making the difference of
** 			addresses or last index digit if no decimal point
** @10		Adapting the index for the new string
** @11		Takes care of copying all characters besides numbers before
** 			dec point
** @12-19	Here we copy / increment (when needed) the numbers before the
** 			decimal point
** @12-13	Case: as long as there is a '0' in the number before we want
**			to keep rounding up. But for the first item, there won't be a '0'
**			so we check for '\0' (for non-decimal) and '.' (for decimal)
**			j-- is for traversing the string from right to left
** @15-16	Case: if we reached '\0', if means we have incremented
**			to '9' all digits and we need to add a '1' to the first char of
**			new string (w/o counting the sign)
** @17-18	Case: either another round up to '0' or the last round up. In case
**			of the last round up, the loop basically ends there
*/

static char		*round_before_decimal(char *str_nb, int length)
{
	char	*new_str_nb;
	int		new_length;
	int		i;
	int		j;

	new_length = get_new_length(str_nb, length);
	if (!(new_str_nb = calloc(new_length + 1, sizeof(char))))
		return (0);
	i = ft_strchr(str_nb, '.') ? ft_strchr(str_nb, '.') - str_nb : length;
	j = new_length == length ? i : i + 1;
	copy_after_decimal(str_nb, new_str_nb, length, new_length);
	while (j-- >= 0 && (new_str_nb[j + 1] == '.' ||
			new_str_nb[j + 1] == '0' || new_str_nb[j + 1] == 0))
	{
		if (str_nb[--i] == 0 || str_nb[i] == '-')
			new_str_nb[j] = '1';
		else
			new_str_nb[j] = str_nb[i] == '9' ? '0' : str_nb[i] + 1;
	}
	free(str_nb);
	return (new_str_nb);
}

/*
** Check if the rounding requires a new digit (i.e. 99 -> 100)
** @param:	- [char *] string formatted float
**			- [int] total length of the number (sign incl.)
** @return:	[int] length + 1 if necessary
** Line-by-line comments:
** @5-6		If after traversing all digits == 9, we get to a '.', it must mean
**			that all numbers before the decimal point are ripe for a round up
*/

static int		get_new_length(char *str_nb, int length)
{
	if (*str_nb == '-')
		str_nb++;
	while (*str_nb == '9')
		str_nb++;
	if (*str_nb == '.' || *str_nb == 0)
		return (length + 1);
	else
		return (length);
}

/*
** Function created to win space on round_before_decimal()
** It takes care of copying all characters besides numbers before dec point
** @param:	- [char *] string formatted float before round up
**			- [char *] string formatted float after round up
**			- [int] total length of the number before round up (sign incl.)
**			- [int] total length of the number after round up (sign incl.)
** @return:	[void] string manipulation
** Line-by-line comments:
** @1		i = old string index
** @2		j = new string index
** @4		Finding the index of the decimal point by making the difference of
** 			addresses or last index digit if no decimal point
** @5		Adapting the index for the new string
** @6-7		If same length as before, we can simply copy everything and just
** 			change the relevant numbers
** @8-11	If not the same, we want to copy the '-' sign (if needed) and all
**			characters after the decimal point (if precision > 0). Meaning
**			for positive non decimal numbers we don't copy anything
*/

static void		copy_after_decimal(char *str_nb,
									char *new_str_nb,
									int length,
									int new_length)
{
	int		i;
	int		j;

	i = ft_strchr(str_nb, '.') ? ft_strchr(str_nb, '.') - str_nb : length;
	j = new_length == length ? i : i + 1;
	if (new_length == length)
		ft_strlcpy(new_str_nb, str_nb, length + 1);
	else
	{
		if (*str_nb == '-')
			*new_str_nb = '-';
		if (ft_strchr(str_nb, '.'))
			ft_strcpy(new_str_nb + j, str_nb + i);
	}
}
