/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:29:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/21 21:40:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ftoa2.h"

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
** @10		Get the index of the decimal point of the old string
** @11		Get the index of the decimal point of the new string
** @12		Takes care of copying all characters besides numbers before
** 			dec point
** @13-22	Here we copy / increment (when needed) the numbers before the
** 			decimal point
** @13-14	Case: as long as there is a '0' in the number before we want
**			to keep rounding up. But for the first item, there won't be a '0'
**			so we check for '\0' (for non-decimal) and '.' (for decimal)
**			j-- is for traversing the string from right to left
** @16-17	Case: if we reached '\0', if means we have incremented
**			to '9' all digits and we need to add a '1' to the first char of
**			new string (w/o counting the sign)
** @18-19	Case: either another round up to '0' or the last round up. In case
**			of the last round up, the loop basically ends there
*/

char		*round_before_decimal(char *str_nb, int length)
{
	char	*new_str_nb;
	int		new_length;
	int		i;
	int		j;

	new_length = get_new_length(str_nb, length);
	new_str_nb = malloc((new_length + 1) * sizeof(char));
	if (!new_str_nb)
		return (0);
	i = get_pos_dec_point_old_str(str_nb, length);
	j = get_pos_dec_point_new_str(i, length, new_length);
	copy_after_decimal(str_nb, new_str_nb, length, new_length);
	while (j-- >= 0 && (new_str_nb[j + 1] == '.' ||
			new_str_nb[j + 1] == '0' || new_str_nb[j + 1] == 0))
	{
		if (--i < 0 || str_nb[i] == '-')
			new_str_nb[j] = '1';
		else if (str_nb[i] == '9')
			new_str_nb[j] = '0';
		else
			new_str_nb[j] = str_nb[i] + 1;
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

static int	get_new_length(char *str_nb, int length)
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
** @4		Get the index of the decimal point of the old string
** @5		Get the index of the decimal point of the new string
** @6-7		If same length as before, we can simply copy everything and just
** 			change the relevant numbers
** @8-14	If not the same, we want to copy the '-' sign (if needed) and all
**			characters after the decimal point (if precision > 0). Meaning
**			for positive non decimal numbers we don't copy anything
*/

static void	copy_after_decimal(char *str_nb,
									char *new_str_nb,
									int length,
									int new_length)
{
	int		i;
	int		j;

	i = get_pos_dec_point_old_str(str_nb, length);
	j = get_pos_dec_point_new_str(i, length, new_length);
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

/*
** Get the index of the decimal point of the old string
** @param:	- [char *] string formatted float number
**			- [int] length of the number prior to potential increase in size
**                  to rounding up
** @return:	[int] index of the decimal point in the old string
** Line-by-line comments:
** @6		Finding the index of the decimal point by making the difference of
** 			addresses
** @8		If no decimal point found then we use the last index digit
*/

static int	get_pos_dec_point_old_str(char *str_nb, int length_old_str)
{
	int		index_decimal_point;
	char	*ptr_decimal_point;

	ptr_decimal_point = ft_strchr(str_nb, '.');
	if (ptr_decimal_point)
		index_decimal_point = ptr_decimal_point - str_nb;
	else
		index_decimal_point = length_old_str;
	return (index_decimal_point);
}

/*
** what_it_does_in_80_chars
** @param:	- [int] index of the decimal point in the old string or the last nb
**			- [int] length of the old string
** @return:	[int] index of the decimal point in the new string
** Line-by-line comments:
** @3-4		If the same length, it means that index of the old string is valid
**			for the new one
** @5-6		If not the same length then we know that the integral part of the
**			number will get an additional number so we need to add 1 to the old
**			index to get the position of the decimal point in the new string
*/

static int	get_pos_dec_point_new_str(int index_old_str,
		int length,
		int new_length)
{
	int	index_decimal_point;

	if (new_length == length)
		index_decimal_point = index_old_str;
	else
		index_decimal_point = index_old_str + 1;
	return (index_decimal_point);
}
