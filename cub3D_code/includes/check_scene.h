/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:50:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/01 09:04:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_SCENE_H
# define CHECK_SCENE_H

# include "cub3d.h"

void	check_cub_extention(char *file);
void	check_resolution(int arr[]);
void	check_texture(char *texture_path, char *texture_name);
void	check_color(int arr[], char *color_name);
void	check_map(t_scene *scene);
int		is_map_enclosed(char **map, int height, int width);
int		has_one_start_position(char **map);
void	get_start_position(char **map, int start_position[]);

#endif
