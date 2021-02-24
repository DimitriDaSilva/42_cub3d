/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:44:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/24 19:09:20 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_OTHERS_H
# define UTILS_OTHERS_H

# include "cub3d.h"

/*
** utils_others1
*/

void	unload_strs(char **strs);
double	rad_to_deg(double rad);
double	deg_to_rad(double deg);
double	normalize_radian(double radian);
int		create_argb(int a, int r, int g, int b);

/*
** utils_others2
*/

void	check_arguments(int argc, char *argv[], char *mode);
int		check_extension(char *file, char *extension);
void	ft_realloc_protected(void **ptr, size_t orig_size, size_t new_size);

#endif
