/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:17:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 14:18:47 by dda-silv         ###   ########.fr       */
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

# ifndef OS
	# define K_ESC 53
	# define K_W 13
	# define K_A 0
	# define K_S 1
	# define K_D 2
	# define K_LEFT_ARROW 123
	# define K_RIGHT_ARROW 124
# else
	# define K_ESC 65307
	# define K_W 122
	# define K_A 113
	# define K_S 115
	# define K_D 100
	# define K_LEFT_ARROW 65361
	# define K_RIGHT_ARROW 65363
# endif

/*
** X11 Events
*/

# define DESTROY_NOTIFY 17
# define CLIENT_MESSAGE 33
# define KEY_PRESS 02
# define KEY_RELEASE 03

/*
** iMac resolution
*/

# define MAX_RES_WIDTH 2560
# define MAX_RES_HEIGHT 1440


#endif
