/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screenshot.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:07:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:31:08 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_SCREENSHOT_H
# define GET_SCREENSHOT_H

# include "cub3d.h"

void	update(t_game *game);
void	draw(t_game *game);
void	save_image_in_bmp(t_game *game);
void	write_bmp_header(t_game *game, int fd);
void	write_dib_header(t_game *game, int fd);
void	write_body(t_game *game, int fd);

#endif
