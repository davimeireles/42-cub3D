/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:14:57 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/09 14:38:27 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

/*
███████ ██████  ██████   ██████  ██████  
██      ██   ██ ██   ██ ██    ██ ██   ██ 
█████   ██████  ██████  ██    ██ ██████  
██      ██   ██ ██   ██ ██    ██ ██   ██ 
███████ ██   ██ ██   ██  ██████  ██   ██
*/

/**
 * @brief Will send a error message to file descriptor 2 and exit the program.
 *
 * @param type Enum type from the error to check what message need to print.
 * @param cub3d Struct containing all the parameters for the program.
 */
void	p_error(t_error type, t_cub3d *cub3d);

/*
██    ██ ████████ ██ ██      ███████      ██ 
██    ██    ██    ██ ██      ██          ███ 
██    ██    ██    ██ ██      ███████      ██ 
██    ██    ██    ██ ██           ██      ██ 
 ██████     ██    ██ ███████ ███████      ██
*/

/**
 * @brief Used to compare two strings.
 *
 * @param s1 First string to be compared with the second one.
 * @param s2 Second string to be compared with the first one.
 * @return Returns 1 if the string was different or 0 if its equal.
 */
int		ft_strcmp(char *s1, char *s2);

/**
 * @brief Will print on the terminal *array[] passed by parameter.
 *
 * @param matrix *array[] with the info to be printed.
 */
void	print_colored_matrix(char *matrix[]);

/*
██    ██ ████████ ██ ██      ███████     ██████  
██    ██    ██    ██ ██      ██               ██ 
██    ██    ██    ██ ██      ███████      █████  
██    ██    ██    ██ ██           ██     ██      
 ██████     ██    ██ ███████ ███████     ███████
*/

/**
 * @brief Will receive a row and will check how many words it have.
 *
 * @param row The row passed by parameter to check it.
 * @return Returns the number of words inside the row.
 */
int		count_words(char *row);
/**
 * @brief Check how many rows the file passed by parameter has.
 *
 * @param fd The file opened.
 * @param textures Struct containing all the textures for the program.
 */
void	count_file_rows(int fd, t_textures *textures);
/**
 * @brief Fill the file opened and creat a new *array[] with the information.
 *
 * @param fd The file opened.
 * @param textures Struct containing all the textures for the program.
 * @return Returns the new *array[] with the information extracted from the file.
 */
char	**pass_data_array(int fd, t_textures *textures);
/**
 * @brief Find the position where the configs finished and start the map.
 *
 * @param data_info Array with the information extracted from opened input file.
 * @return Integer with the number of the line that starts the real map
 * skipping the configuration.
 */
int		find_map_start(char **data_info);
/**
 * @brief Will freed the memory from the information
 * passed by parameter.
 *
 * @param data_file Array with the information extracted from opened input file.
 * @param s_line Line used to extract information
 * splitted from the data_file array.
 * @param cub3D Struct containing all the parameters for the program.
 */
void	free_arrays(char **data_file, char **s_line, t_cub3d *cub3D);

/*
██    ██ ████████ ██ ██      ███████     ██████  
██    ██    ██    ██ ██      ██               ██ 
██    ██    ██    ██ ██      ███████      █████  
██    ██    ██    ██ ██           ██          ██ 
 ██████     ██    ██ ███████ ███████     ██████ 
*/

/**
 * @brief
 *
 * @param map
 * @param line
 * @param cub3D
 * @return
 */
char	*padding_aux(char *map, char *line, t_cub3d *cub3D);
/**
 * @brief
 *
 * @param data_file
 * @param s_line
 * @param cub3D
 * @param s_rgb
 */
void	check_rgb_character(char **data_file, char **s_line,
			t_cub3d *cub3D, char **s_rgb);
bool	initialize_visited(char **map, t_cub3d *cub3D);

/**
 * @brief Converts the string passed by parameter to a integer representing a color in RGB.
 * @param str The string passed by parameter to be converted.
 * @return An integer representing the color in RGB.
 */
int	get_color(char *str);

/**
 * @brief Will set the pixels of the image passed by parameter with the color passed by parameter.
 */
void	*ft_pixelset(void *s, int c, size_t n);

/**
 * @brief Returns the absolute value in double.
 */
double	ft_abs(double n);

#endif