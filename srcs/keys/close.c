/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:42:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/11 18:04:34 by txisto-d         ###   ########.fr       */
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
		if (cub3d->map->f_map[(int)(cub3d->player->x + cub3d->player->dir_x * cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
			cub3d->player->x += cub3d->player->dir_x * cub3d->player->speed;
		if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y + cub3d->player->dir_y * cub3d->player->speed)] != '1')
			cub3d->player->y += cub3d->player->dir_y * cub3d->player->speed;
	}
	if (keycode == D_ARROW)
	{
		if (cub3d->map->f_map[(int)(cub3d->player->x - cub3d->player->dir_x * cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
			cub3d->player->x -= cub3d->player->dir_x * cub3d->player->speed;
		if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y - cub3d->player->dir_y * cub3d->player->speed)] != '1')
			cub3d->player->y -= cub3d->player->dir_y * cub3d->player->speed;
	}

	if (keycode == R_ARROW)
	{
		double oldDirX = cub3d->player->dir_x;
		cub3d->player->dir_x = cub3d->player->dir_x * cos(-cub3d->player->rotation) - cub3d->player->dir_y * sin(-cub3d->player->rotation);
		cub3d->player->dir_y = oldDirX * sin(-cub3d->player->rotation) + cub3d->player->dir_y * cos(-cub3d->player->rotation);
		double oldPlaneX = cub3d->raycaster->ray.plane[X];
		cub3d->raycaster->ray.plane[X] = cub3d->raycaster->ray.plane[X] * cos(-cub3d->player->rotation) - cub3d->raycaster->ray.plane[Y] * sin(-cub3d->player->rotation);
		cub3d->raycaster->ray.plane[Y] = oldPlaneX * sin(-cub3d->player->rotation) + cub3d->raycaster->ray.plane[Y] * cos(-cub3d->player->rotation);
	}
	if (keycode == L_ARROW)
	{
		double oldDirX = cub3d->player->dir_x;
		cub3d->player->dir_x = cub3d->player->dir_x * cos(cub3d->player->rotation) - cub3d->player->dir_y * sin(cub3d->player->rotation);
		cub3d->player->dir_y = oldDirX * sin(cub3d->player->rotation) + cub3d->player->dir_y * cos(cub3d->player->rotation);
		double oldPlaneX = cub3d->raycaster->ray.plane[X];
		cub3d->raycaster->ray.plane[X] = cub3d->raycaster->ray.plane[X] * cos(cub3d->player->rotation) - cub3d->raycaster->ray.plane[Y] * sin(cub3d->player->rotation);
		cub3d->raycaster->ray.plane[Y] = oldPlaneX * sin(cub3d->player->rotation) + cub3d->raycaster->ray.plane[Y] * cos(cub3d->player->rotation);
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