/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:23:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/15 17:51:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
███    ███  █████   ██████ ██████   ██████  ███████
████  ████ ██   ██ ██      ██   ██ ██    ██ ██
██ ████ ██ ███████ ██      ██████  ██    ██ ███████
██  ██  ██ ██   ██ ██      ██   ██ ██    ██      ██
██      ██ ██   ██  ██████ ██   ██  ██████  ███████
*/

# define FOV 90
# define SCREEN_Y 360 //720
# define SCREEN_X 640 //1280
# define FULL_XY 230400//921600
# define HALF_XY 115200 //460800

# define WHITE 0xFFFFFF
# define BLACK 0
# define GREY 0x808080
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000

# define M_PI 3.14159265358979323846
# define X 0
# define Y 1

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

/*
██      ██ ██████  ██████   █████  ██████  ██ ███████ ███████
██      ██ ██   ██ ██   ██ ██   ██ ██   ██ ██ ██      ██
██      ██ ██████  ██████  ███████ ██████  ██ █████   ███████
██      ██ ██   ██ ██   ██ ██   ██ ██   ██ ██ ██           ██
███████ ██ ██████  ██   ██ ██   ██ ██   ██ ██ ███████ ███████
*/

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>
# include "structs.h"
# include "enums.h"
# include "checker.h"
# include "free.h"
# include "initializer.h"
# include "keys.h"
# include "map.h"
# include "player.h"
# include "screen.h"
# include "utils.h"

/**
 * @brief Main function, will call other functions for execution of the program.
 *
 * @param argc Number of arguments passed.
 * @param argv Arguments e.g(program name and map path).
 * @return Return Success.
 */
int				main(int argc, char **argv);

#endif