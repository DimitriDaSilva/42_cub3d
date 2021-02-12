/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_others.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:05:14 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 17:14:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_OTHERS_H
# define READY_GAME_OTHERS_H

# include "cub3d.h"

void	check_user_res(t_mlx *mlx, t_res *res);
void	set_rays(t_game *game);
void	load_texture(void *mlx, t_texture *texture);

#endif
