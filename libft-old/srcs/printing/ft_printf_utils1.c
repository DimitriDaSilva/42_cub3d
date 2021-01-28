/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:34:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/24 21:23:49 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Adding a space or a plus char if the flag ' ' or '+' have been used
** @param:	- [type] param_value
**			- [char *] a string with all the flags used
** @return:	[type] return_value
** Line-by-line comments:
** @3-5		Check edge cases where no need to add sign: no flags used, the
** 			number is negative, none of ' ' or '+' have been used
** @10		Order is important because if both flags ' ' and '+' have been
**			used, the ' ' is ignored
*/

void	add_sign(char **nb, char *flags)
{
	int		length;
	char	*tmp_new_nb;

	if (*flags == 0 || **nb == '-' || !(ft_strchr(flags, ' ') ||
		ft_strchr(flags, '+')))
		return ;
	length = 1 + (int)ft_strlen(*nb);
	if (!(tmp_new_nb = calloc(length + 1, sizeof(char))))
		return ;
	*tmp_new_nb = ft_strchr(flags, '+') ? '+' : ' ';
	ft_strlcpy(tmp_new_nb + 1, *nb, length);
	free(*nb);
	*nb = tmp_new_nb;
}

/*
** Adds 0 at the left of ints when precision is higher than length of int
** @param:	- [char **nbr] 	Number in a str format. Ptr to a ptr because we
** 							need to free and allocate more space
**  		- [int precision] Number passed after the . in the format. For
** 							ints, the precision defines the length of
** 							the number. If precision > length of the int,
** 							then we add add 0 to the left of the int
** @return: [void] The value is passed through the pointer **nb
** Line-by-line comments:
** @10-12	Check if precision > nbr. The '-' doesn't count so we need to
**			make a specific use case for it. If not, return.
** @13		The length of the new_nb depends on the sign
** @16-17	The '-' sign needs to go before the padding of 0s
*/

void	add_padding(char **nb, int precision)
{
	int		length_old_nb;
	int		length_new_nb;
	char	*tmp_new_nb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	length_old_nb = (int)ft_strlen(*nb);
	if ((ft_strchr("-+ ", (*nb)[i]) && length_old_nb - 1 >= precision) ||
		(!ft_strchr("-+ ", (*nb)[i]) && length_old_nb >= precision))
		return ;
	length_new_nb = ft_strchr("-+ ", (*nb)[i]) ? precision + 2 : precision;
	if (!(tmp_new_nb = calloc(length_new_nb + 1, sizeof(char))))
		return ;
	if (ft_strchr("-+ ", (*nb)[i]) && length_new_nb--)
		tmp_new_nb[j++] = (*nb)[i++];
	while (length_new_nb-- > length_old_nb)
		tmp_new_nb[j++] = '0';
	while (length_new_nb-- != -1)
		tmp_new_nb[j++] = (*nb)[i++];
	free(*nb);
	*nb = tmp_new_nb;
}

/*
** With the flag #, hex numbers are prefixed with 0x or 0X
** @param:	- [char **nbr] 	Number in a str format. Ptr to a ptr because we
** 							need to free and allocate more space
**			- [char] type here can be p, x or X
**			- [char *] string with all the flags used
** @return: [void] The value is passed through the pointer **nb
** Line-by-line comments:
** @4-5		Edge case: even if # used, if the nb is equal to 0, no prefix
**			needs to be outputed
**			Also checking if neither of 'p' or '#' have been used. If not,
**			no hex prefix to output
*/

void	add_hex_prefix(char **nb, char type, char *flags)
{
	int		length;
	char	*tmp_new_nb;

	if (!(type == 'p' || ft_strchr(flags, '#')) || is_all_zeros(*nb))
		return ;
	length = (int)ft_strlen(*nb) + 2;
	if (!(tmp_new_nb = calloc(length + 1, sizeof(char))))
		return ;
	tmp_new_nb[0] = '0';
	tmp_new_nb[1] = (type == 'X') ? 'X' : 'x';
	ft_strlcpy(tmp_new_nb + 2, *nb, length);
	free(*nb);
	*nb = tmp_new_nb;
}

int		is_all_zeros(char *nb)
{
	while (*nb)
	{
		if (*nb != '0')
			return (0);
		nb++;
	}
	return (1);
}

/*
** If the flag # is used with a float, it forces a decimal point (even if
** precision = 0)
** @param:	- [char **nbr] 	Number in a str format. Ptr to a ptr because we
** 							need to free and allocate more space
**			- [t_format] all 5 fields: flags, width, precision, size, type
** @return: [void] The value is passed through the pointer **nb
** Line-by-line comments:
** @4-6		Checking if # not used or if a decimal point is already there
*/

void	add_point(char **nb, t_format *settings)
{
	size_t	length;
	char	*tmp_new_nb;

	if (!ft_strchr(settings->flags, '#') || ft_strchr(*nb, '.'))
		return ;
	length = ft_strlen(*nb) + 1;
	if (!(tmp_new_nb = calloc(length + 1, sizeof(char))))
		return ;
	ft_strlcpy(tmp_new_nb, *nb, length);
	tmp_new_nb[length - 1] = '.';
	free(*nb);
	*nb = tmp_new_nb;
}
