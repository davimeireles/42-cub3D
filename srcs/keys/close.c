/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:42:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/11 00:41:27 by dmeirele         ###   ########.fr       */
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
	if (keycode == U_ARROW) // cima
	{
		if (cub3d->map->f_map[(int)(cub3d->player->x + cub3d->player->dir_x * MOVE_SPEED)][(int)(cub3d->player->y)] == '0')
			cub3d->player->x += cub3d->player->dir_x * MOVE_SPEED;
		if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y + cub3d->player->dir_y * MOVE_SPEED)] == '0')
			cub3d->player->y += cub3d->player->dir_y * MOVE_SPEED;
	}
	if (keycode == D_ARROW) // baixo
	{
		if (cub3d->map->f_map[(int)(cub3d->player->x - cub3d->player->dir_x * MOVE_SPEED)][(int)(cub3d->player->y)] == '0')
			cub3d->player->x -= cub3d->player->dir_x * MOVE_SPEED;
		if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y - cub3d->player->dir_y * MOVE_SPEED)] == '0')
			cub3d->player->y -= cub3d->player->dir_y * MOVE_SPEED;
	}
	if (keycode == R_ARROW) // direita
	{
		double oldDirX = cub3d->player->dir_x;
		cub3d->player->dir_x = cub3d->player->dir_x * cos(-ROT_SPEED) - cub3d->player->dir_y * sin(-ROT_SPEED);
		cub3d->player->dir_y = oldDirX * sin(-ROT_SPEED) + cub3d->player->dir_y * cos(-ROT_SPEED);
		double oldPlaneX = cub3d->raycaster->ray.plane[0];
		cub3d->raycaster->ray.plane[0] = cub3d->raycaster->ray.plane[0] * cos(-ROT_SPEED) - cub3d->raycaster->ray.plane[1] * sin(-ROT_SPEED);
		cub3d->raycaster->ray.plane[1] = oldPlaneX * sin(-ROT_SPEED) + cub3d->raycaster->ray.plane[1] * cos(-ROT_SPEED);
	}
	if (keycode == L_ARROW) // esquerda
	{
		double oldDirX = cub3d->player->dir_x;
		cub3d->player->dir_x = cub3d->player->dir_x * cos(ROT_SPEED) - cub3d->player->dir_y * sin(ROT_SPEED);
		cub3d->player->dir_y = oldDirX * sin(ROT_SPEED) + cub3d->player->dir_y * cos(ROT_SPEED);
		double oldPlaneX = cub3d->raycaster->ray.plane[0];
		cub3d->raycaster->ray.plane[0] = cub3d->raycaster->ray.plane[0] * cos(ROT_SPEED) - cub3d->raycaster->ray.plane[1] * sin(ROT_SPEED);
		cub3d->raycaster->ray.plane[1] = oldPlaneX * sin(ROT_SPEED) + cub3d->raycaster->ray.plane[1] * cos(ROT_SPEED);
	}
	return (0);
}

int	close_window_x(t_cub3d *cub3d)
{
	mlx_loop_end(cub3d->connection);
	free_mlx(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}