/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:32:50 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:36:57 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PLAYER_H
# define INIT_PLAYER_H

# include "cub3d.h"

void	get_start_position(t_player *player, char **grid);
double	get_starting_orientation(char orientation);

#endif
