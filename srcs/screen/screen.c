/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/16 16:25:19 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	time_frame(t_cub3d *cub3d);

int	screen_loader(t_cub3d *cub3d)
{
	char	*fps;

	time_frame(cub3d);
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
	background_loader(cub3d);
	raycaster(cub3d);
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->screen->screen->img_ptr, 0, 0);
	minimap_loader(cub3d);
	fps = ft_itoa((int)(1 / cub3d->timer->frame_time));
	mlx_string_put(cub3d->connection, cub3d->window, 10, 10, WHITE, fps);
	free(fps);
	fps = 0;
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

static void	time_frame(t_cub3d *cub3d)
{
	cub3d->timer->old_time = cub3d->timer->time;
	gettimeofday(cub3d->timer->tv, NULL);
	cub3d->timer->time = (double) cub3d->timer->tv->tv_sec
		+ (double) cub3d->timer->tv->tv_usec / 1000000;
	cub3d->timer->frame_time = cub3d->timer->time - cub3d->timer->old_time;
	cub3d->player->speed = cub3d->timer->frame_time * cub3d->player->sprint;
	cub3d->player->rotation = cub3d->timer->frame_time * 2.0;
}
