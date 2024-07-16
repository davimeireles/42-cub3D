/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:42:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/16 16:10:09 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(cub3d->connection);
		free_cub3d(cub3d);
		exit(EXIT_SUCCESS);
	}
	if (keycode == XK_w)
		cub3d->player->move_y = 1;
	if (keycode == XK_s)
		cub3d->player->move_y = -1;
	if (keycode == XK_d)
		cub3d->player->move_x = 1;
	if (keycode == XK_a)
		cub3d->player->move_x = -1;
	if (keycode == XK_Right)
		cub3d->player->rotate += 1;
	if (keycode == XK_Left)
		cub3d->player->rotate -= 1;
	if (keycode == XK_Shift_L)
		cub3d->player->sprint = 2;
	return (0);
}

int	key_release(int key, t_cub3d *cub3d)
{
	if (key == XK_w && cub3d->player->move_y == 1)
		cub3d->player->move_y = 0;
	if (key == XK_s && cub3d->player->move_y == -1)
		cub3d->player->move_y = 0;
	if (key == XK_a && cub3d->player->move_x == -1)
		cub3d->player->move_x = 0;
	if (key == XK_d && cub3d->player->move_x == 1)
		cub3d->player->move_x = 0;
	if (key == XK_Right && cub3d->player->rotate <= 1)
		cub3d->player->rotate = 0;
	if (key == XK_Left && cub3d->player->rotate >= -1)
		cub3d->player->rotate = 0;
	if (key == XK_Shift_L)
		cub3d->player->sprint = 1;
	return (0);
}

int	close_window_x(t_cub3d *cub3d)
{
	mlx_loop_end(cub3d->connection);
	free_cub3d(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
