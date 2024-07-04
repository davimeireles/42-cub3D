/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:13:39 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/04 17:26:50 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H

# include "cub3d.h"
/*
 ██████ ██    ██ ██████      ██ ███    ██ ██ ████████ 
██      ██    ██ ██   ██     ██ ████   ██ ██    ██    
██      ██    ██ ██████      ██ ██ ██  ██ ██    ██    
██      ██    ██ ██   ██     ██ ██  ██ ██ ██    ██    
 ██████  ██████  ██████      ██ ██   ████ ██    ██  
*/

/**
 * @brief Will initialize all the variables from the struct.
 *
 * @param cub3d Struct containing all the parameters for the program.
 */
void	initialize_cub(t_cub3d **cub3d);

/*
 ██████   █████  ███    ███ ███████     ██ ███    ██ ██ ████████ 
██       ██   ██ ████  ████ ██          ██ ████   ██ ██    ██    
██   ███ ███████ ██ ████ ██ █████       ██ ██ ██  ██ ██    ██    
██    ██ ██   ██ ██  ██  ██ ██          ██ ██  ██ ██ ██    ██    
 ██████  ██   ██ ██      ██ ███████     ██ ██   ████ ██    ██ 
*/

/**
 * @brief Initialize the game.
 * @param cub3d the struct containing all the data.
 */
void    game_init(t_cub3d *cub3d);


/*
████████ ███████ ██   ██ ████████ ██    ██ ██████  ███████
   ██    ██       ██ ██     ██    ██    ██ ██   ██ ██        
   ██    █████     ███      ██    ██    ██ ██████  █████  
   ██    ██       ██ ██     ██    ██    ██ ██   ██ ██       
   ██    ███████ ██   ██    ██     ██████  ██   ██ ███████
*/

/**
 * @brief API loader.
 */
t_img	load_texture(void *mlx, char *path, t_cub3d *cub3D);

/**
 * @brief Load all the necessary textures.
 * @param cub3d the struct containing all the data.
 */
void    init_textures(t_cub3d * cub3d);

/*
██     ██ ██ ███    ██ ██████   ██████  ██     ██ 
██     ██ ██ ████   ██ ██   ██ ██    ██ ██     ██ 
██  █  ██ ██ ██ ██  ██ ██   ██ ██    ██ ██  █  ██ 
██ ███ ██ ██ ██  ██ ██ ██   ██ ██    ██ ██ ███ ██ 
 ███ ███  ██ ██   ████ ██████   ██████   ███ ███  
*/

/**
 * @brief Initialize new window and process things to run the game.
 * @param cub3D Struct containing all the parameters for the program.
 */
void	window_init(t_cub3d *cub3D);

#endif