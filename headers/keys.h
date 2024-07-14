/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:14:48 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 04:47:33 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "cub3d.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# define	L_ARROW 65361
# define	U_ARROW 65362
# define	R_ARROW 65363
# define	D_ARROW 65364
# define	A_KEY 97
# define	D_KEY 100
# define	S_KEY 115
# define	W_KEY 119

/*
 ██████ ██       ██████  ███████ ███████ 
██      ██      ██    ██ ██      ██      
██      ██      ██    ██ ███████ █████   
██      ██      ██    ██      ██ ██      
 ██████ ███████  ██████  ███████ ███████
*/

/**
 * @brief Window closes on the X
 * 
 * @param cub3D Struct containing all the parameters for the program.
 */
int		close_window_x(t_cub3d *cub3D);

/**
 * @brief Handle pressed buttons to do same action.
 *
 * @param keycode Value of the pressed button.
 * @param cub3D Struct containing all the parameters for the program.
 * @return Simples return 0.
 */
int		key_handler(int keycode, t_cub3d *cub3D);
// int		mouse_move(int x, int y, t_cub3d *cub3d);


int		key_release(int key, t_cub3d *cub3d);
int		mouse_move(int x, int y, t_cub3d *cub3d);
void	mouse_position(t_cub3d *cub3d, int x, int y);




int	move_forward(t_cub3d *cub3d);
int	move_back(t_cub3d *cub3d);
int move_left(t_cub3d *cub3d);
int	move_right(t_cub3d *cub3d);
int	rotate_left(t_cub3d *cub3d);
int	rotate_right(t_cub3d *cub3d);


#endif