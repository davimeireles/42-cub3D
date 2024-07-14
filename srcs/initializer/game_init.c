/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:03:56 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 04:40:14 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    game_init(t_cub3d *cub3d)
{
	mlx_hook(cub3d->window, 17, 0, (int (*)(void *))close_window_x, cub3d);
	mlx_hook(cub3d->window, KeyPress, KeyPressMask, key_handler, cub3d);
	mlx_hook(cub3d->window, KeyRelease, KeyReleaseMask, key_release, cub3d);
	mlx_hook(cub3d->window, MotionNotify, PointerMotionMask, mouse_move, cub3d);
	mlx_loop(cub3d->connection);
	mlx_loop_end(cub3d->connection);
	free_mlx(cub3d);
}
