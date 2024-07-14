/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:42:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 04:47:27 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_cub3d *cub3d)
{
	if (keycode == 65307)
	{
		mlx_loop_end(cub3d->connection);
		free_mlx(cub3d);
		exit(EXIT_SUCCESS);
	}
	if (keycode == U_ARROW || keycode == W_KEY)
		cub3d->player->move_x = move_forward(cub3d);
	if (keycode == D_ARROW || keycode == S_KEY)
		cub3d->player->move_y = move_back(cub3d);
	if (keycode == D_KEY)
		cub3d->player->move_x = move_right(cub3d);
	if (keycode == A_KEY)
		cub3d->player->move_x = move_left(cub3d);
	if (keycode == R_ARROW)
		cub3d->player->rotate += rotate_right(cub3d);
	if (keycode == L_ARROW)
		cub3d->player->rotate -= rotate_left(cub3d);
	screen_loader(cub3d);
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == W_KEY && cub3d->player->move_y == 1)
		cub3d->player->move_y = 0;
	if (key == S_KEY && cub3d->player->move_y == -1)
		cub3d->player->move_y = 0;
	if (key == A_KEY && cub3d->player->move_x == -1)
		cub3d->player->move_x = 0;
	if (key == D_KEY && cub3d->player->move_x == 1)
		cub3d->player->move_x = 0;
	if (key == R_ARROW && cub3d->player->rotate <= 1)
		cub3d->player->rotate = 0;
	if (key == L_ARROW && cub3d->player->rotate >= -1)
		cub3d->player->rotate = 0;
	return (0);
}

void	mouse_position(t_cub3d *cub3d, int x, int y)
{
	if (x > cub3d->screen->width - 20)
	{
		x = 20;
		mlx_mouse_move(cub3d->connection, cub3d->window, x, y);
	}
	if (x < 20)
	{
		x = cub3d->screen->width - 20;
		mlx_mouse_move(cub3d->connection, cub3d->window, x, y);
	}
}

int	mouse_move(int x, int y, t_cub3d *cub3d)
{
	static int	old_x = SCREEN_X / 2;

	mouse_position(cub3d, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		rotate_left(cub3d);
	else if (x > old_x)
		rotate_right(cub3d);
	screen_loader(cub3d);
	old_x = x;
	return (0);
}

int	move_forward(t_cub3d *cub3d)
{
	if (cub3d->map->f_map[(int)(cub3d->player->x + cub3d->player->dir_x * cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x += cub3d->player->dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y + cub3d->player->dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y += cub3d->player->dir_y * cub3d->player->speed;
	return (1);
}

int	move_back(t_cub3d *cub3d)
{
	if (cub3d->map->f_map[(int)(cub3d->player->x - cub3d->player->dir_x * cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x -= cub3d->player->dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y - cub3d->player->dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y -= cub3d->player->dir_y * cub3d->player->speed;
	return (-1);
}

int move_left(t_cub3d *cub3d)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = -cub3d->player->dir_y;
	perp_dir_y = cub3d->player->dir_x;
	if (cub3d->map->f_map[(int)(cub3d->player->x + perp_dir_x * cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x += perp_dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y + perp_dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y += perp_dir_y * cub3d->player->speed;
	return (-1);
}
int	move_right(t_cub3d *cub3d)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = cub3d->player->dir_y;
	perp_dir_y = -cub3d->player->dir_x;
	if (cub3d->map->f_map[(int)(cub3d->player->x + perp_dir_x * cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x += perp_dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y + perp_dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y += perp_dir_y * cub3d->player->speed;
	return (1);
}


int	rotate_left(t_cub3d *cub3d)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(cub3d->player->rotation) - cub3d->player->dir_y * sin(cub3d->player->rotation);
	cub3d->player->dir_y = oldDirX * sin(cub3d->player->rotation) + cub3d->player->dir_y * cos(cub3d->player->rotation);
	oldPlaneX = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x * cos(cub3d->player->rotation) - cub3d->player->plane_y * sin(cub3d->player->rotation);
	cub3d->player->plane_y = oldPlaneX * sin(cub3d->player->rotation) + cub3d->player->plane_y * cos(cub3d->player->rotation);
	return (-1);
}

int rotate_right(t_cub3d *cub3d)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(-cub3d->player->rotation) - cub3d->player->dir_y * sin(-cub3d->player->rotation);
	cub3d->player->dir_y = oldDirX * sin(-cub3d->player->rotation) + cub3d->player->dir_y * cos(-cub3d->player->rotation);
	oldPlaneX = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x * cos(-cub3d->player->rotation) - cub3d->player->plane_y * sin(-cub3d->player->rotation);
	cub3d->player->plane_y = oldPlaneX * sin(-cub3d->player->rotation) + cub3d->player->plane_y * cos(-cub3d->player->rotation);
	return (1);
}

int	close_window_x(t_cub3d *cub3d)
{
	mlx_loop_end(cub3d->connection);
	free_mlx(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
