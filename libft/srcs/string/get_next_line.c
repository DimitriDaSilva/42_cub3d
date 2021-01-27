/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:51:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/25 20:22:50 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	int			i;

	if (read(fd, 0, 0) != -1)
		return (-1);
	if (!(buf = malloc(1)))
		return (-1);
	if (!(*line = malloc(MAX_LINE)))
		return (-1);
	i = 0;
	while (read(fd, buf, 1))
	{
		if (*buf == '\n')
		{
			(*line)[i] = '\0';
			free(buf);
			return (1);
		}
		(*line)[i++] = *buf;
	}
	(*line)[i] = '\0';
	free(buf);
	return (0);
}
