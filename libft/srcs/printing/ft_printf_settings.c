/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:47:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/24 20:42:09 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_settings.h"

/*
** Get all fields from the fmt string. After each subfunction,
** the fmt string is incremented (when relevant)
** @param:	- [const char *] string inputted with specified formats
**			- [t_format] all 5 fields: flags, width, precision, size, type
** Line-by-line comments:
** @8-12	Edge case: when width < 0, printf acts like it has the flag '-'
** @13-18	Edge case: for certain type specifiers, when both the flag '0'
** 			and a precision is used, the '0' is ignored
** @17		'9' but could be anything else. Just to overwrite '0'
*/

void		get_settings(const char **fmt, t_format *settings)
{
	int		position_flag;

	get_flags(fmt, settings->flags);
	settings->width = get_width(fmt);
	settings->precision = get_precision(fmt);
	get_size(fmt, settings->size);
	settings->type = **fmt;
	if (settings->width < 0)
	{
		settings->flags[0] = '-';
		settings->width = ft_abs_lg(settings->width);
	}
	if (ft_strchr(settings->flags, '0') &&
		ft_strchr("diuxX", settings->type) && settings->precision >= 0)
	{
		position_flag = ft_strchr(settings->flags, '0') - settings->flags;
		settings->flags[position_flag] = '9';
	}
}

/*
** @param:	- [const char *] string inputted with specified formats
** @return:	[char *] 0 or more flags among (-+0 #)
** Line-by-line comments:
** @7-8		Edge case: when both 0 and - are used, 0 is ignored
*/

static void	get_flags(const char **fmt, char *flags)
{
	int		i;

	i = 0;
	while (ft_strchr("-0# +", **fmt))
		flags[i++] = *(*fmt)++;
	flags[i] = 0;
	if (ft_strchr(flags, '0') && ft_strchr(flags, '-'))
		flags[ft_strchr(flags, '0') - flags] = '9';
}

/*
** Width can be an int or an *, in which case, we get it from arg_list
** @param:	- [const char *] string inputted with specified formats
** @return:	[int] width
** Line-by-line comments:
** @12		Increment the string with the length of the width's number
*/

static int	get_width(const char **fmt)
{
	int	width;

	width = 0;
	if (**fmt == '*')
	{
		(*fmt)++;
		width = va_arg(g_arg_list, int);
	}
	else if (ft_isdigit(**fmt))
	{
		width = ft_atoi(*fmt);
		(*fmt) += get_size_lg(width);
	}
	return (width);
}

/*
** Precision is specified after a point. Like the width, the wildcard *
** means that the precision is specified in the arg_list
** @param:	- [const char *] string inputted with specified formats
** @return:	[int] precision
** Line-by-line comments:
** @3		When only the point is used, it means that precision = 0.
** 			Precision -1 represents that no precision has been specified
** @6		Increment from the '.' to the next characters. Check if that
** 			characters is '*'. Ugly but no space.
** @13-14	Edge case: only the '.' has been used
** @17-18	Edge case: the precision number is padded with useless 0 so
** 			we go through all 0 until != 0
** @19-20	Edge case: only 0s as the precision
** @22		Increment the string with the length of the precision's number
*/

static int	get_precision(const char **fmt)
{
	int	precision;

	precision = -1;
	if (**fmt != '.')
		return (precision);
	if ((*fmt)++ && **fmt == '*')
	{
		(*fmt)++;
		precision = va_arg(g_arg_list, int);
	}
	else
	{
		if (!ft_isdigit(**fmt))
			return (0);
		else
		{
			while (**fmt == '0')
				(*fmt)++;
			if (!ft_isdigit(**fmt))
				return (0);
			precision = ft_atoi(*fmt);
			(*fmt) += get_size_lg(precision);
		}
	}
	return (precision);
}

/*
** @param:	- [const char *] string inputted with specified formats
** @return:	[char *] size can be h, hh, l or ll to complement specifiers: diuxX
**					For instance, %lld represents a long long int
** Line-by-line comments:
** @5-6		Checking if **fmt is neither h nor l
** @4-5		The second char can only either be the same as the first or not
** 			being a size specifier anymore. If it is, add it to size and
**			increment to go to the next field
*/

static void	get_size(const char **fmt, char *size)
{
	if (!ft_strchr("lh", **fmt))
		return ;
	size[0] = *(*fmt)++;
	if (**fmt == size[0])
		size[1] = *(*fmt)++;
	size[2] = 0;
}
