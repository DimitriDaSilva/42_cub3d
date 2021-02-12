/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:08:18 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 10:41:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_others.h"

void	check_arguments(int argc, char *argv[], char *mode)
{
	if ((argc == 2 || argc == 3) && !is_cub(argv[1]))
	{
		ft_printf("Error\nScene description file with wrong extention.\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2 && is_cub(argv[1]))
		ft_strcpy(mode, "PLAY");
	else if (argc == 3 && ft_strcmp("--save", argv[2]) != 0)
	{
		ft_printf("Error\nWrong flag. Use --save.\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc == 3 && ft_strcmp("--save", argv[2]) == 0)
		ft_strcpy(mode, "SAVE");
	else
	{
		ft_printf("Error\nWrong number of arguments.\n");
		exit(EXIT_SUCCESS);
	}
}

/*
** @param:	- [char	*] name of the file passed in as argument of the cub3d
** Line-by-line comments:
** @4		Before checking the extension, I need to check it's size otherwise
**			I risk doing a SEGFAULT
*/

int	is_cub(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (!(len > 4 && !ft_strncmp(&file[len - 4], ".cub", 5)))
		return (0);
	else
		return (1);
}

void	ft_realloc_protected(void **ptr, size_t orig_size, size_t new_size)
{
	*ptr = ft_realloc(*ptr, orig_size, new_size);
	if (*ptr == 0)
		exit(EXIT_SUCCESS);
}
