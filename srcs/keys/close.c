/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:42:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/11 14:14:01 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	esc_hook(int keycode, t_cub3d *cub3d)
{
	if (keycode == 65307)
	{
		mlx_loop_end(cub3d->connection);
		free_mlx(cub3d);
		exit(EXIT_SUCCESS);
	}
	if (keycode == U_ARROW)
	{
		if (cub3d->map->f_map[(int)(cub3d->player->x + cub3d->player->dir_x * MOVE_SPEED)][(int)(cub3d->player->y)] != '1')
			cub3d->player->x += cub3d->player->dir_x * MOVE_SPEED;
		if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y + cub3d->player->dir_y * MOVE_SPEED)] != '1')
			cub3d->player->y += cub3d->player->dir_y * MOVE_SPEED;
	}
	if (keycode == D_ARROW)
	{
		if (cub3d->map->f_map[(int)(cub3d->player->x - cub3d->player->dir_x * MOVE_SPEED)][(int)(cub3d->player->y)] != '1')
			cub3d->player->x -= cub3d->player->dir_x * MOVE_SPEED;
		if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y - cub3d->player->dir_y * MOVE_SPEED)] != '1')
			cub3d->player->y -= cub3d->player->dir_y * MOVE_SPEED;
	}

	if (keycode == R_ARROW)
	{
		double oldDirX = cub3d->player->dir_x;
		cub3d->player->dir_x = cub3d->player->dir_x * cos(-ROT_SPEED) - cub3d->player->dir_y * sin(-ROT_SPEED);
		cub3d->player->dir_y = oldDirX * sin(-ROT_SPEED) + cub3d->player->dir_y * cos(-ROT_SPEED);
		double oldPlaneX = cub3d->raycaster->ray.plane[X];
		cub3d->raycaster->ray.plane[X] = cub3d->raycaster->ray.plane[X] * cos(-ROT_SPEED) - cub3d->raycaster->ray.plane[Y] * sin(-ROT_SPEED);
		cub3d->raycaster->ray.plane[Y] = oldPlaneX * sin(-ROT_SPEED) + cub3d->raycaster->ray.plane[Y] * cos(-ROT_SPEED);
	}
	if (keycode == L_ARROW)
	{
		double oldDirX = cub3d->player->dir_x;
		cub3d->player->dir_x = cub3d->player->dir_x * cos(ROT_SPEED) - cub3d->player->dir_y * sin(ROT_SPEED);
		cub3d->player->dir_y = oldDirX * sin(ROT_SPEED) + cub3d->player->dir_y * cos(ROT_SPEED);
		double oldPlaneX = cub3d->raycaster->ray.plane[X];
		cub3d->raycaster->ray.plane[X] = cub3d->raycaster->ray.plane[X] * cos(ROT_SPEED) - cub3d->raycaster->ray.plane[Y] * sin(ROT_SPEED);
		cub3d->raycaster->ray.plane[Y] = oldPlaneX * sin(ROT_SPEED) + cub3d->raycaster->ray.plane[Y] * cos(ROT_SPEED);
	}
	screen_loader(cub3d);
	return (0);
}

int	close_window_x(t_cub3d *cub3d)
{
	mlx_loop_end(cub3d->connection);
	free_mlx(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}