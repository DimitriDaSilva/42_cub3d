/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:44:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/11 00:15:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_OTHERS_H
# define UTILS_OTHERS_H


void	unload_strs(char **strs);
double	rad_to_deg(double rad);
double	deg_to_rad(double deg);
double	normalize_radian(double radian);
void	check_arguments(int argc, char *argv[], char *mode);

#endif

