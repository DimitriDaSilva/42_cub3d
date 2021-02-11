/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:43:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/10 19:24:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_others.h"

void	unload_strs(char **strs)
{
	while (*strs)
		free(*strs++);
}

double	rad_to_deg(double rad)
{
	return (rad * 180.0 / M_PI);
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

/*
** Makes sure the radian stays between 0 and 2 * PI
** @param:	- [double] radian
** @return:	[double] radian normalized
*/

double	normalize_radian(double radian)
{
	double	full_circle;

	full_circle = deg_to_rad(360);
	radian = fmod(radian, full_circle);
	if (radian < 0)
		radian += full_circle;
	return (radian);
}

void	check_arguments(int argc, char *argv[], char *mode)
{
	if ((argc == 2 || argc == 3) && !is_cub(argv[1]))
	{
		ft_printf("Error\nScene description file with wrong extention.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2 && is_cub(argv[1]))
		ft_strcpy(mode, "PLAY");
	else if (argc == 3 && ft_strcmp("--save", argv[2]) != 0)
	{
		ft_printf("Error\nWrong flag. Use --save.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 3 && ft_strcmp("--save", argv[2]) == 0)
		ft_strcpy(mode, "SAVE");
	else
	{
		ft_printf("Error\nWrong number of arguments.\n");
		exit(EXIT_FAILURE);
	}
}
