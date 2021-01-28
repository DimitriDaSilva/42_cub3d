/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:52:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/28 15:12:50 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

void	get_map(int fd, t_map *map)
{
	char	*line;
	int		i;

	line = 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		while (*line[i] && ft_isspace(line[i]))
			i++;
		if (line[i] == 'F')
			get_resolution(line + i);
		free(line);
	}
}