/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:23:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/14 21:57:57 by txisto-d         ###   ########.fr       */
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


/*
███████ ████████ ██████  ██    ██  ██████ ████████ ███████
██         ██    ██   ██ ██    ██ ██         ██    ██
███████    ██    ██████  ██    ██ ██         ██    ███████
		██    ██    ██   ██ ██    ██ ██         ██         ██
███████    ██    ██   ██  ██████   ██████    ██    ███████
*/

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
	bool		u;
	bool		d;
	bool		l;
	bool		r;
	bool		u_l;
	bool		u_r;
	bool		d_l;
	bool		d_r;
	bool		**visited;
}				t_flood_aux;

typedef struct s_textures
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			file_rows;
	void		*texture_img;
	char		*texture_data;
	int			texture_width;
	int			texture_height;
	int			texture_bits_per_pixel;
	int			texture_line_length;
	int			texture_endian;
	t_flood_aux	*flood;
}				t_textures;

typedef struct s_img
{
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*data;
	int			width;
	int			height;
}				t_img;

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
	char		p_direction;
	int			rows;
	int			columns;
	int			start_map;
	t_textures	*textures;
	t_img		*text_imgs;
}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	double		rotation;
	int			fov;
	int			rotate;
	int			move_x;
	int			move_y;
	int			moved;
}				t_player;

typedef struct s_screen
{
	t_img		*screen;
	t_img		*north;
	t_img		*east;
	t_img		*south;
	t_img		*west;
	int			ceiling;
	int			floor;
	int			height;
	int			width;
}				t_screen;

typedef struct s_minimap
{
	t_img		*bkg;
	t_img		*player;
	t_img		*wall;
	t_img		*floor;
	t_img		*dir;
}				t_minimap;

typedef struct s_ray
{
	double		pos[2];
	double		dir[2];
	double		plane[2];
	double		ray_dir[2];
	int			tile[2];
	double		delta_distance[2];
	double		side_distance[2];
	double		step[2];
	double		perp_wall_distance;
	double		camera_x;
	double		wall_x;
	int			hit;
	int			side;
}				t_ray;

typedef struct s_raycaster
{
	t_ray		ray;
	double		time;
	double		old_time;
}				t_raycaster;

typedef struct s_cub3d
{
	void		*connection;
	void		*window;
	t_screen	*screen;
	t_map		*map;
	t_player	*player;
	t_minimap	*minimap;
	t_raycaster	*raycaster;
}				t_cub3d;

/*
███████ ███    ██ ██    ██ ███    ███ ███████
██      ████   ██ ██    ██ ████  ████ ██
█████   ██ ██  ██ ██    ██ ██ ████ ██ ███████
██      ██  ██ ██ ██    ██ ██  ██  ██      ██
███████ ██   ████  ██████  ██      ██ ███████
*/

typedef enum e_error
{
	N_ARGS,
	MAP_NAME,
	OPEN_ERROR,
	CONFIGS,
	MEMORY,
	INVALID_MAP,
	RGB,
	TEXTURES
}				t_error;

/*
███████ ██    ██ ███    ██  ██████ ████████ ██  ██████  ███    ██ ███████
██      ██    ██ ████   ██ ██         ██    ██ ██    ██ ████   ██ ██
█████   ██    ██ ██ ██  ██ ██         ██    ██ ██    ██ ██ ██  ██ ███████
██      ██    ██ ██  ██ ██ ██         ██    ██ ██    ██ ██  ██ ██      ██
██       ██████  ██   ████  ██████    ██    ██  ██████  ██   ████ ███████
*/

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

void			raycaster(t_cub3d *cub3d);

#endif