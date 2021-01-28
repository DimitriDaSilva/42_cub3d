/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:17:30 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/28 23:34:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_SCENE_H
# define GET_SCENE_H

# include "cub3D.h"

static int	is_map(char *line);
static void	get_map(int fd, char *line, t_scene *scene);
static char	**cpy_map(int fd, char *line);
static size_t	get_width(char **strs);
static size_t	get_height(char **strs);
static void	get_data(char **strs, t_scene *scene);
static void get_color(char *str, int arr[]);
static void	unload_strs(char **strs);

#endif
