/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:13:39 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/09 12:44:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H

# include "cub3d.h"
/*
 ██████ ██    ██ ██████     
██      ██    ██ ██   ██   
██      ██    ██ ██████     
██      ██    ██ ██   ██     
 ██████  ██████  ██████ 
*/

/**
 * @brief Will initialize all the variables from the struct.
 *
 * @param cub3d Struct containing all the parameters for the program.
 */
void	initialize_cub(t_cub3d **cub3d);

/*
 ██████   █████  ███    ███ ███████  
██       ██   ██ ████  ████ ██         
██   ███ ███████ ██ ████ ██ █████     
██    ██ ██   ██ ██  ██  ██ ██          
 ██████  ██   ██ ██      ██ ███████    
*/

/**
 * @brief Initialize the game.
 * @param cub3d the struct containing all the data.
 */
void    game_init(t_cub3d *cub3d);

/*
███    ███ ██ ███    ██ ██ ███    ███  █████  ██████  
████  ████ ██ ████   ██ ██ ████  ████ ██   ██ ██   ██ 
██ ████ ██ ██ ██ ██  ██ ██ ██ ████ ██ ███████ ██████  
██  ██  ██ ██ ██  ██ ██ ██ ██  ██  ██ ██   ██ ██      
██      ██ ██ ██   ████ ██ ██      ██ ██   ██ ██ 
*/

/**
 * @brief Initialize the minimap.
 */
void	minimap_init(t_cub3d *cub3d);

/*
██████  ██       █████  ██    ██ ███████ ██████  
██   ██ ██      ██   ██  ██  ██  ██      ██   ██ 
██████  ██      ███████   ████   █████   ██████  
██      ██      ██   ██    ██    ██      ██   ██ 
██      ███████ ██   ██    ██    ███████ ██   ██
*/

/**
 * @brief Initialize the player.
 */
void    player_init(t_cub3d *cub3d);

/*
██████   █████  ██    ██  ██████  █████  ███████ ████████ ███████ ██████  
██   ██ ██   ██  ██  ██  ██      ██   ██ ██         ██    ██      ██   ██ 
██████  ███████   ████   ██      ███████ ███████    ██    █████   ██████  
██   ██ ██   ██    ██    ██      ██   ██      ██    ██    ██      ██   ██ 
██   ██ ██   ██    ██     ██████ ██   ██ ███████    ██    ███████ ██   ██
*/

void  raycaster_init(t_cub3d *cub3d);

/*
████████ ███████ ██   ██ ████████ ██    ██ ██████  ███████
   ██    ██       ██ ██     ██    ██    ██ ██   ██ ██        
   ██    █████     ███      ██    ██    ██ ██████  █████  
   ██    ██       ██ ██     ██    ██    ██ ██   ██ ██       
   ██    ███████ ██   ██    ██     ██████  ██   ██ ███████
*/

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