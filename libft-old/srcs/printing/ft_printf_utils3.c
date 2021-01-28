/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:22:59 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 11:02:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Counts the numbers of digits in the integral part of a number with a
** decimal point
** @param:	- [double] Number with a fractional part
** @return:	[size_t] numbers of digits in the integral part
** Line-by-line comments:
** @4-5		If the number is already below 1, the count should be 1
*/

size_t	get_count_int(double nb)
{
	size_t	count;

	nb = ft_abs_dl(nb);
	if (nb < 1)
		return (1);
	count = 0;
	while (nb > 1)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

/*
** @param:	- [char *] String formatted float number
** Line-by-line comments:
** @5-6		Checking the index after which we find only 0
** @7-8		If that index comes right after the decimal point, we can
**			place NULL to overwrite it
** @9-10	Else we overwrite the '0' with a NULL terminator
*/

void	remove_trailing_zero(char *nb)
{
	if (*nb == '-')
		nb++;
	if (*nb == '0')
		nb++;
	while (*nb && !is_all_zeros(nb))
		nb++;
	if (*nb == 0)
		return ;
	else if (*(nb - 1) == '.')
		*(nb - 1) = 0;
	else
		*nb = 0;
}

/*
** Removes the middle zeros in scientific notation. (e.g. "2.34000e+02"
** -> "2.34e+02"). We traverse the string from right to left
** @param:	- [char *] String formatted scientific notation number
** Line-by-line comments:
** @8-9		Finding the index after which there is only 0s (besides the
**			exponent suffix)
** @10-11	If i == 0, it mean we reached the beginning of the number and
** 			hence no 0 need to be removed
** @12-15	We move the exponent suffix to the left
*/

void	remove_middle_zero(char *nb)
{
	int		i;
	size_t	length;

	length = ft_strlen(nb);
	i = length - 1;
	while (nb[i + 1] != 'e')
		i--;
	while (nb[i] == '0')
		i--;
	if (i == 0)
		return ;
	else if (nb[i] == '.')
		ft_strlcpy(nb + i, nb + length - 4, 5);
	else
		ft_strlcpy(nb + i + 1, nb + length - 4, 5);
}
