/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:03:56 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 20:44:21 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_cub3d *cub3d)
{
	mlx_mouse_hide(cub3d->connection, cub3d->window);
	mlx_hook(cub3d->window, 17, 0, (int (*)(void *))close_window_x, cub3d);
	mlx_hook(cub3d->window, KeyPress, KeyPressMask, key_handler, cub3d);
	mlx_hook(cub3d->window, KeyRelease, KeyReleaseMask, key_release, cub3d);
	mlx_hook(cub3d->window, MotionNotify, PointerMotionMask, mouse_move, cub3d);
}
