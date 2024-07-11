/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:03:56 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/10 13:57:48 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    game_init(t_cub3d *cub3d)
{
    mlx_key_hook(cub3d->window, esc_hook, cub3d);
	mlx_hook(cub3d->window, 17, 0, (int (*)(void *))close_window_x, cub3d);
	mlx_loop(cub3d->connection);
	mlx_loop_end(cub3d->connection);
	free_mlx(cub3d);
}