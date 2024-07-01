/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:23:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/05 20:35:04 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef FOV
#  define FOV 90
# endif

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# include <signal.h>
# define MAX_ROWS 100
# define MAX_COLS 100

/*******          STRUCTS          *******/

typedef enum e_error
{
	N_ARGS,
	MAP_NAME,
	OPEN_ERROR,
	CONFIGS,
	MEMORY,
	INVALID_MAP,
	RGB
}	t_error;

/*
 * NO -> North Texture
 * SO -> South Texture
 * WE -> West Texture
 * EA -> East Texture
 * F -> Floor color
 * C -> Ceiling color
*/

typedef struct s_flood_aux
{
	bool	u;
	bool	d;
	bool	l;
	bool	r;
	bool	u_l;
	bool	u_r;
	bool	d_l;
	bool	d_r;
	bool	**visited;
}	t_flood_aux;

typedef struct s_textures
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	file_rows;
	t_flood_aux *flood;
}	t_textures;

typedef struct s_map
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*floor;
	char		*ceiling;
	char		**f_map;
	int			p_position[2];
	int			rows;
	int			columns;
	int			start_map;
	t_textures	*textures;
}	t_map;

typedef struct s_cub3d
{
	void		*connection;
	void		*window;
	t_map		*map;
}	t_cub3d;


/*******          FUNCTIONS          *******/

//	====================				main.c				====================

/**
 * @brief Main function, will call other functions for execution of the program.
 *
 * @param argc Number of arguments passed.
 * @param argv Arguments e.g(program name and map path).
 * @return Return Success.
 */
int		main(int argc, char **argv);

//	====================				error.c				====================

/**
 * @brief Will send a error message to file descriptor 2 and exit the program.
 *
 * @param type Enum type from the error to check what message need to print.
 * @param cub3d Struct containing all the parameters for the program.
 */
void	p_error(t_error type, t_cub3d *cub3d);

//	====================			file_checker.c			====================

/**
 * @brief Checks if inside the file we have all the configurations needed
 * by the program and if this configurations was above from the map struct.
 *
 * @param input Path to the map file.
 * @param cub3d Struct containing all the parameters for the program.
 */
void	check_file_config(char *input, t_cub3d *cub3d);

//	====================		map_checker.c		====================

/**
 * @brief Checks if map contain all that was need to make it a valid map
 * and fill the struct with some information.
 *
 * @param data_file Array with the information extracted from opened input file.
 * @param cub3D Struct containing all the parameters for the program.
 */
void	map_checker(char **data_file, t_cub3d *cub3D);

//	====================		map_checker_2.c		====================

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
 * @param cub3D
 * @return
 */
char	**extract_map_to_struct(char **map, t_cub3d *cub3D);

/**
 * @brief
 *
 * @param map
 * @param cub3D
 * @param x
 * @param y
 * @return
 */
bool	is_valid_map(char **map, t_cub3d *cub3D);

/**
 * @brief
 * 
 * @param map
 * @param cub3D
 * @return
 */
char	**padding_map(char **map, t_cub3d *cub3D);

/**
 * @brief
 * 
 * @param map
 * @param cub3D
 * @return
 */
bool	initialize_visited(char **map, t_cub3d *cub3D);


//	====================		map_checker_3.c		====================

/**
 * @brief
 * 
 * @param cub3D
 * @param filled_map
 */
void	find_player_position(t_cub3d *cub3D, char **filled_map);
/**
 * @brief
 * 
 * @param map
 * @param cub3D
 * @param x
 * @param y
 */
bool flood_fill(char **map, t_cub3d *cub3D, int x, int y);


void	fill_textures_info(char **data_file, t_cub3d *cub3D);



//	====================				cub3d.c				====================

/**
 * @brief Will initialize all the variables from the struct.
 *
 * @param cub3d Struct containing all the parameters for the program.
 */
void	initialize_cub(t_cub3d **cub3d);

//	====================				utils.c				====================

/**
 * @brief Will freed the memory from the struct t_cub3d passed by parameter.
 *
 * @param cub3D Struct containing all the parameters for the program.
 */
void	free_memory(t_cub3d *cub3D);

/**
 * @brief Will split the *array[] passed by parameter.
 *
 * @param split *array[] with the info to be freed.
 */
void	free_splits(char **split);

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

//	====================		utils_2.c		====================

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

//	====================		utils_3.c		====================

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
void	check_rgb_character(char **data_file, char **s_line, t_cub3d *cub3D, char **s_rgb);
bool	initialize_visited(char **map, t_cub3d *cub3D);

//	====================		window_init.c		====================

/**
 * @brief Initialize new window and process things to run the game.
 * @param cub3D Struct containing all the parameters for the program.
 */
void	window_init(t_cub3d *cub3D);
/**
 * @brief Handle pressed buttons to do same action.
 *
 * @param keycode Value of the pressed button.
 * @param cub3D Struct containing all the parameters for the program.
 * @return Simples return 0.
 */
int	key_hook(int keycode, t_cub3d *cub3D);

/**
 * @brief Free memory from mlx scenes.
 *
 * @param cub3D Struct containing all the parameters for the program.
 */
void	free_mlx(t_cub3d *cub3D);

/**
 * @brief Window closes on the X
 * 
 * @param cub3D Struct containing all the parameters for the program.
 */
int	close_window_x(t_cub3d *cub3D);

#endif