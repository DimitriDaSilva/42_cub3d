/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:46:39 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 17:47:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MEM_H
# define UTILS_MEM_H

# include "cub3d.h"

void	free_game(t_game *game);
void	free_scene(t_scene *scene);
void	free_map(t_map *map);

#endif
