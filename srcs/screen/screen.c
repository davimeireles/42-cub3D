/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/15 17:47:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	screen_loader(t_cub3d *cub3d)
{
	background_loader(cub3d);
	raycaster(cub3d);
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->screen->screen->img_ptr, 0, 0);
	if (cub3d->player->move_y == 1)
		move_forward(cub3d);
	if (cub3d->player->move_y == -1)
		move_back(cub3d);
	if (cub3d->player->move_x == 1)
		move_right(cub3d);
	if (cub3d->player->move_x == -1)
		move_left(cub3d);
	if (cub3d->player->rotate >= 1)
		rotate_right(cub3d);
	if (cub3d->player->rotate <= -1)
		rotate_left(cub3d);
	minimap_loader(cub3d);
	return (0);
}

void	background_loader(t_cub3d *cub3d)
{
	ft_pixelset(cub3d->screen->screen->data,
		cub3d->screen->ceiling, HALF_XY);
	ft_pixelset(&cub3d->screen->screen->data[HALF_XY],
		cub3d->screen->floor, HALF_XY);
}

void	minimap_loader(t_cub3d *cub3d)
{
	int			mm_pair[2];
	t_player	*player;

	player = cub3d->player;
	mm_pair[0] = -6;
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->minimap->bkg->img_ptr, SCREEN_X - 145, 25);
	while (++mm_pair[0] <= 5)
	{
		mm_pair[1] = -6;
		while (++mm_pair[1] <= 5)
		{
			mm_pair[1] = mm_pair[1];
			mm_pair[0] = mm_pair[0];
			print_tile(cub3d, (int) cub3d->player->y + mm_pair[1],
				(int) cub3d->player->x + mm_pair[0], mm_pair);
		}
	}
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->minimap->player->img_ptr, SCREEN_X - 140 + 50, 30 + 50);
	tile_n(player, cub3d);
	tile_s(player, cub3d);
	tile_w(player, cub3d);
	tile_e(player, cub3d);
}
