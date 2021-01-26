/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:13:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/26 19:18:16 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int my_key_func(int keycode, void *param)
{
	(void)param;
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		exit(EXIT_SUCCESS);
	}

	return (1);
}

int		main(int argc, char *argv[])
{
	char *file;

	if (argc != 2)
	{
		ft_printf("Scene description file missing\n");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	if (!is_file_valid(file))
		exit(EXIT_FAILURE);
	render_game();
	return (0);
}