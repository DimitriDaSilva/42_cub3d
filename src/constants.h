/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:17:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/24 18:28:11 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/*
** General
*/

# define VALID_CHARS "012NSEW "
# define MINIMAP_RATIO 200
# define MINIMAP_OFFSET 10
# define SCALE 64
# define VIEW_ANGLE 60

/*
** Keycodes
*/

# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT_ARROW 123
# define K_RIGHT_ARROW 124

/*
** X11 Events
*/

# define DESTROY_NOTIFY 17
# define KEY_PRESS 02
# define KEY_RELEASE 03

#endif
