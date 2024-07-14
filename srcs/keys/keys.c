/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:42:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 06:40:01 by dmeirele         ###   ########.fr       */
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

int	close_window_x(t_cub3d *cub3d)
{
	mlx_loop_end(cub3d->connection);
	free_mlx(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
