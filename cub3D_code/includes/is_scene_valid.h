/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene_valid.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:50:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 10:03:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_SCENE_VALID_H
# define IS_SCENE_VALID_H

# include "cub3d.h"

void	check_cub_extention(char *file);
void	check_resolution(int arr[]);
void	check_texture(char *texture_path, char *texture_name);
void	check_color(int arr[], char *color_name);
void	check_map(t_scene *scene);
int		is_map_enclosed(char **map, int height, int width);
int		has_one_start_position(char **map);

#endif
