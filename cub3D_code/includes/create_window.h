/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 08:52:44 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/01 17:30:01 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_WINDOW_H
# define CREATE_WINDOW_H

# include "render_scene.h"

int		close_window_esc(int keycode, t_mlx *mlx);
int		close_window_cross(int keycode, t_mlx *mlx);

#endif
