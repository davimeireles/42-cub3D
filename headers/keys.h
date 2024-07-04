/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:14:48 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/04 17:22:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "cub3d.h"

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
int		esc_hook(int keycode, t_cub3d *cub3D);

#endif