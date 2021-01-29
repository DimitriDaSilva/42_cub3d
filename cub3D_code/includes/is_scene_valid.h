/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scene_valid.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:50:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/29 17:55:28 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_SCENE_VALID_H
# define IS_SCENE_VALID_H

# include "cub3d.h"

void	check_cub_extention(char *file);
void	check_texture(char *texture_path, char *texture_name);
void	check_color(int arr[], char *color_name);

#endif
