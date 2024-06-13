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
	INVALID_MAP
}	t_error;

/*
 * NO -> North Texture
 * SO -> South Texture
 * WE -> West Texture
 * EA -> East Texture
 * F -> Floor color
 * C -> Ceiling color
*/

typedef enum e_view
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_view;

typedef struct s_textures
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	start_map;
}	t_textures;

typedef struct s_map
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	void	*floor;
	void	*ceiling;
	char	**f_map;
	int 	p_position[2];
	int 	rows;
	int 	columns;
}	t_map;

typedef struct s_cub3d
{
	void		*connection;
	void		*window;
	t_map		*map;
}	t_cub3d;

/*******          FUNCTIONS          *******/

//	====================				main.c				====================

int		main(int argc, char **argv);

//	====================				error.c				====================

void	p_error(t_error type);

//	====================			file_checker.c			====================

void	check_file(char *input, t_textures *textures);
void	check_map_config(int fd, t_textures *textures);

//	====================			map_input.c			====================

char	**input_map(char *input, t_textures *textures, t_cub3d *cub3D);

//	====================			map_checker.c			====================

void	map_checker(t_cub3d *cub3D);

//	====================				cub3d.c				====================

void	initialize_cub(t_cub3d **cub3d);

//	====================				utils.c				====================

void	free_splits(char **split, char *line);
int		ft_strcmp(char *s1, char *s2);
void	init_stack(t_textures *textures);
void	print_colored_matrix(char *matrix[]);
void	print_colored_char(char c);
void	free_memory(t_cub3d *cub3D);



#endif