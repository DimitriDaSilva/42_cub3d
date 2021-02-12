/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:17:30 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 11:13:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_SCENE_H
# define GET_SCENE_H

# include "cub3d.h"

/*
** get_scene1
*/
void	get_data(char **strs, t_scene *scene);
void	get_resolution(char **strs, t_res *res);
void	get_texture(char *texture_path, t_texture *texture);
void	get_color(char *str, t_color *color);

/*
** get_scene2
*/
int		is_map(char *line);
void	get_map(int fd, char *line, t_map *map);
char	**cpy_map(int fd, char *line, int *width);
size_t	get_width(char **strs);
char	**convert_tabs_to_spaces(char **strs, int width, int height);

#endif
