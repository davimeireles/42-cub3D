/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:38:19 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/16 16:24:27 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int			sprint;
}				t_player;

typedef struct s_timer
{
	struct timeval	*restrict tv;
	double			time;
	double			old_time;
	double			frame_time;
}				t_timer;

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
	t_timer		*timer;
}				t_cub3d;

#endif