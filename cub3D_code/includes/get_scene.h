/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:17:30 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/30 10:45:58 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_SCENE_H
# define GET_SCENE_H

# include "cub3d.h"

void	get_scene(int fd, t_scene *scene);
int		is_map(char *line);
void	get_data(char **strs, t_scene *scene);
void	get_resolution(char **strs, int arr[]);
void	get_color(char *str, int arr[]);
void	get_map(int fd, char *line, t_scene *scene);
char	**cpy_map(int fd, char *line);
char	**convert_tabs_to_spaces(char **strs, t_scene *scene);
size_t	get_width(char **strs);
size_t	get_height(char **strs);

#endif
