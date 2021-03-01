/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:08:18 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 17:31:16 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_others.h"

void	check_arguments(int argc, char *argv[], char *mode)
{
	if ((argc == 2 || argc == 3) && !check_extension(argv[1], ".cub"))
	{
		printf("Error\nScene description file with wrong extention.\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2 && check_extension(argv[1], ".cub"))
		ft_strcpy(mode, "PLAY");
	else if (argc == 3 && ft_strcmp("--save", argv[2]) != 0)
	{
		printf("Error\nWrong flag. Use --save.\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc == 3 && ft_strcmp("--save", argv[2]) == 0)
		ft_strcpy(mode, "SAVE");
	else
	{
		printf("Error\nWrong number of arguments.\n");
		exit(EXIT_SUCCESS);
	}
}

/*
** Check if the file has the extension specified
** @param:	- [char	*] file name
** 			- [char	*] extension tested
** Line-by-line comments:
** @6-7		Before checking the extension, I need to check it's size otherwise
**			I risk doing a SEGFAULT
** @8-9		I need to find the index where the extension would start and I need
**			to check len_ext + 1 to make sure the NULL char is also a match
*/

int		check_extension(char *file, char *extension)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(extension);
	if (len_file <= len_ext)
		return (0);
	else if (!ft_strncmp(&file[len_file - len_ext], extension, len_ext + 1))
		return (1);
	else
		return (0);
}

void	ft_realloc_protected(void **ptr, size_t orig_size, size_t new_size)
{
	*ptr = ft_realloc(*ptr, orig_size, new_size);
	if (*ptr == 0)
		exit(EXIT_SUCCESS);
}
