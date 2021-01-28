/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:24:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/27 10:20:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_file_valid(char *file)
{
	int		fd;
	char	*line;

	line = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Error\nWrong file path or file corrupted.\n");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	if (close(fd) == -1)
	{
		ft_printf("Error\nCould not close open file.\n");
		exit(EXIT_FAILURE);
	}
}