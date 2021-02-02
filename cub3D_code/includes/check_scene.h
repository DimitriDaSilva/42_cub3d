/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:50:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:16:01 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_SCENE_H
# define CHECK_SCENE_H

# include "cub3d.h"

/*
** check_scene1.c file
*/
void	check_scene(t_scene *scene, char *file);
void	check_cub_extention(char *file);
void	check_resolution(t_res *res);
void	check_texture(char *texture_path, char *texture_name);
void	check_color(t_color *color, char *color_name);

/*
** check_scene2.c file
*/
void	check_map(t_map *map);
int		is_map_enclosed(char **map, int height, int width);
int		has_one_start_position(char **map);

#endif
