/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 06:39:33 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/14 20:21:44 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	old_x = x;
	return (0);
}
