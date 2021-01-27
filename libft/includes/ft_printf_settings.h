/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_settings.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:40:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/22 19:30:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SETTINGS_H
# define FT_PRINTF_SETTINGS_H

# include "ft_printf.h"

static void	get_flags(const char **fmt, char *flags);
static int	get_width(const char **fmt);
static int	get_precision(const char **fmt);
static void	get_size(const char **fmt, char *size);

#endif
