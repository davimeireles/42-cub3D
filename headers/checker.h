/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:11:53 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/04 17:21:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "cub3d.h"

/*
███████ ██ ██      ███████ 
██      ██ ██      ██      
█████   ██ ██      █████   
██      ██ ██      ██      
██      ██ ███████ ███████
*/

/**
 * @brief Checks if inside the file we have all the configurations needed
 * by the program and if this configurations was above from the map struct.
 *
 * @param input Path to the map file.
 * @param cub3d Struct containing all the parameters for the program.
 */
void	check_file_config(char *input, t_cub3d *cub3d);

/*
███    ███  █████  ██████  
████  ████ ██   ██ ██   ██ 
██ ████ ██ ███████ ██████  
██  ██  ██ ██   ██ ██      
██      ██ ██   ██ ██                                                                                
*/

/**
 * @brief Checks if map contain all that was need to make it a valid map
 * and fill the struct with some information.
 *
 * @param data_file Array with the information extracted from opened input file.
 * @param cub3D Struct containing all the parameters for the program.
 */
void	map_checker(char **data_file, t_cub3d *cub3D);

/*
██████   █████  ██████  ██████  ██ ███    ██  ██████  
██   ██ ██   ██ ██   ██ ██   ██ ██ ████   ██ ██       
██████  ███████ ██   ██ ██   ██ ██ ██ ██  ██ ██   ███ 
██      ██   ██ ██   ██ ██   ██ ██ ██  ██ ██ ██    ██ 
██      ██   ██ ██████  ██████  ██ ██   ████  ██████ 
*/

/**
 * @brief Checks if the extension map name is a valid one.
 *
 * @param input Path to the map file.
 * @param cub3d Struct containing all the parameters for the program.
 */
void	check_map_name(char *input, t_cub3d *cub3d);

/**
 * @brief
 *
 * @param map
 * @param cub3D Struct containing all the parameters for the program.
 * @return
 */
char	**extract_map_to_struct(char **map, t_cub3d *cub3D);

/**
 * @brief
 *
 * @param map
 * @param cub3D Struct containing all the parameters for the program.
 * @param x
 * @param y
 * @return
 */
bool	is_valid_map(char **map, t_cub3d *cub3D);

/**
 * @brief
 * 
 * @param map
 * @param cub3D Struct containing all the parameters for the program.
 * @return
 */
char	**padding_map(char **map, t_cub3d *cub3D);

/**
 * @brief
 * 
 * @param map
 * @param cub3D Struct containing all the parameters for the program.
 * @return
 */
bool	initialize_visited(char **map, t_cub3d *cub3D);

/*
███████ ██       ██████   ██████  ██████  
██      ██      ██    ██ ██    ██ ██   ██ 
█████   ██      ██    ██ ██    ██ ██   ██ 
██      ██      ██    ██ ██    ██ ██   ██ 
██      ███████  ██████   ██████  ██████  
*/

/**
 * @brief
 * 
 * @param cub3D Struct containing all the parameters for the program.
 * @param filled_map
 */
void	find_player_position(t_cub3d *cub3D, char **filled_map);
/**
 * @brief
 * 
 * @param map
 * @param cub3D Struct containing all the parameters for the program.
 * @param x
 * @param y
 */
bool	flood_fill(char **map, t_cub3d *cub3D, int x, int y);
/**
 * @brief
 * 
 * @param data_file Array with the information extracted from opened input file.
 * @param cub3D Struct containing all the parameters for the program.
 */
void	fill_textures_info(char **data_file, t_cub3d *cub3D);

#endif