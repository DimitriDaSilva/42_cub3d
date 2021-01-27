/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:34:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 11:01:08 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Brings the nb to a one non-null digit number while counting the number of
** operations to get there (i.e. the exponent). It also put the number to the
** correct format for scientific notation (i.e. "-02" or "+15")
** @param:	- [double *] The address of the number to be able to effectively
**                       change if for the parent function that called it
**			- [char **] pointer to string to reallocate space when needed
** Line-by-line comments:
** @9-10	Checks if the number is equal to 0. If the number hasn't changed
**			after being multiplicated by 10 then it means = 0
*/

void	get_exp_str(double *nb, char **exponent)
{
	int		count;
	double	cpy;

	count = 0;
	cpy = *nb;
	while ((-1 < *nb && 1 / *nb < 0) || (0 < *nb && *nb < 1))
	{
		*nb *= 10;
		if (cpy == *nb)
			break ;
		count--;
	}
	while (*nb < -10 || 10 < *nb)
	{
		*nb /= 10;
		count++;
	}
	*exponent = ft_itoa(count);
	add_sign(exponent, "+");
	add_padding(exponent, 2);
}

/*
** Concat of float formatted string + 'e' + exponent
** @param:	- [double *] The address of the number to be able to effectively
**                       change if for the parent function that called it
**			- [char **] pointer to string to reallocate space when needed
** Line-by-line comments:
** @5-6		New string needs to have the whole original number + "e+00" + '\0'
*/

void	add_exponent(char **nb, char **exponent)
{
	int		i;
	char	*tmp;

	i = ft_strlen(*nb);
	if (!(tmp = malloc((i + 4 + 1) * sizeof(char))))
		return ;
	ft_strcpy(tmp, *nb);
	tmp[i] = 'e';
	tmp[i + 1] = 0;
	ft_strncat(tmp + i + 1, *exponent, 3);
	tmp[i + 5] = '\0';
	free(*exponent);
	free(*nb);
	*nb = tmp;
}

/*
** In some rounding edge cases, I add "10.0e+01". This function removes the
** '0' from the integral part and increments the exponent
** @param:	- [char *] string formatted scientific number
** Line-by-line comments:
** @5-7		The edge case this function solves only arises with numbers with
**			two integral numbers. We are here checking if we have either a '.'
**			or the 'e' right after the first number
** @8		Having the length helps us finding the index of exponent suffix
** @11-12	Short way to ignore whether or not the number is negative
** @13		In theory, useless line because the '1' is already there. But
**			without it, I get a memory bug while compiling with sanitizer
** 			flags
** @16-17	Copying all the necessary 0 except for the last one
** @18-19	Accounting for an edge case to increment() function. "e-01"
**			needs to become "e+00" but the function can't both reduce to 00
**			while also changing the sign
** @22		Increment or decrement the number formatted string based on the
**			sign
** @23		Once the exponent is fixed, we move the 4 characters "e+00" one
**			place the left
*/

void	adjust_rounding(char *nb)
{
	int		length;
	int		i;
	char	sign_exp;

	if ((nb[0] == '-' && (nb[2] == '.' || nb[2] == 'e')) ||
		(nb[0] != '-' && (nb[1] == '.' || nb[1] == 'e')))
		return ;
	length = ft_strlen(nb);
	sign_exp = nb[length - 3] == '+' ? '+' : '-';
	i = 0;
	while (nb[i] != '0')
		i++;
	nb[i - 1] = '1';
	if (nb[i + 1] == '.')
		nb[i++] = '.';
	while (nb[i + 1] != 'e')
		nb[i++] = '0';
	if (!ft_strncmp(nb + length - 4, "e-01", 5))
		ft_strncpy(nb + length - 5, "e+00", 5);
	else
	{
		increment(nb + length - 2, sign_exp);
		ft_strlcpy(nb + i, nb + length - 4, 5);
	}
}

/*
** Increment or decrement the number formatted string based on the sign
** @param:	- [char *] two digit string formatted number
**			- [char] '+' or '-'. If '+' we increment. Else we decrement
** Line-by-line comments:
** @8		If we see '0' as the second digit it means we need to increment
**			the first number
**			If we see NULL if means we are about to check the second digit
*/

void	increment(char *nb, char sign)
{
	int		i;

	i = ft_strlen(nb);
	while (i-- >= 0 && (nb[i + 1] == '0' || nb[i + 1] == '\0'))
	{
		if (sign == '+')
			nb[i] = nb[i] == '9' ? '0' : nb[i] + 1;
		else
			nb[i] = nb[i] == '0' ? '9' : nb[i] - 1;
	}
}

/*
** Brings the nb to a one non-null digit number while counting the number of
** operations to get there (i.e. the exponent). The difference with
** get_exp_str() is that it doesn't change the value. It just get the exponent
** @param:	- [double] Number with a fractional part
** Line-by-line comments:
** @9-10	Checks if the number is equal to 0. If the number hasn't changed
**			after being multiplicated by 10 then it means = 0
*/

int		get_exp_nb(double nb)
{
	int		count;
	double	cpy;

	count = 0;
	cpy = nb;
	while ((-1 < nb && 1 / nb < 0) || (0 < nb && nb < 1))
	{
		nb *= 10;
		if (cpy == nb)
			break ;
		count--;
	}
	nb = ft_round(nb);
	while (nb <= -10 || 10 <= nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
