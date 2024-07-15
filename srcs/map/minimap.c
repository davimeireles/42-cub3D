/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:21:27 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/15 17:48:20 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tile(t_cub3d *cub3d, int x, int y, int *mm_pair)
{
	if (x < 0 || y < 0 || x >= cub3d->map->columns || y >= cub3d->map->rows)
		return ;
	if (cub3d->map->f_map[y][x] == '1')
	{
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->wall->img_ptr, SCREEN_X - 90 + (mm_pair[1] * 10),
			80 + (mm_pair[0] * 10));
	}
	else
	{
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->floor->img_ptr, SCREEN_X - 90 + (mm_pair[1] * 10),
			80 + (mm_pair[0] * 10));
	}
}

void	tile_n(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_x < -0.66)
	{
		if (player->dir_y > -0.33 && player->dir_y < 0.33)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 54, 30 + 50);
		if (player->dir_y > 0.33 && player->dir_y < 0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 56, 30 + 50);
		if (player->dir_y > 0.66 && player->dir_y < 1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 58, 30 + 50);
		if (player->dir_y < -0.33 && player->dir_y > -0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 52, 30 + 50);
		if (player->dir_y < -0.66 && player->dir_y > -1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 50, 30 + 50);
	}
}

void	tile_s(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_x > 0.66)
	{
		if (player->dir_y > -0.33 && player->dir_y < 0.33)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 54, 30 + 58);
		if (player->dir_y > 0.33 && player->dir_y < 0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 56, 30 + 58);
		if (player->dir_y > 0.66 && player->dir_y < 1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 58, 30 + 58);
		if (player->dir_y < -0.33 && player->dir_y > -0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 52, 30 + 58);
		if (player->dir_y < -0.66 && player->dir_y > -1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 50, 30 + 58);
	}
}

void	tile_w(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_y < -0.66)
	{
		if (player->dir_x > -0.33 && player->dir_x < 0.33)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 50, 30 + 54);
		if (player->dir_x > 0.33 && player->dir_x < 0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 50, 30 + 56);
		if (player->dir_x > 0.66 && player->dir_x < 1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 50, 30 + 58);
		if (player->dir_x < -0.33 && player->dir_x > -0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 50, 30 + 52);
		if (player->dir_x < -0.66 && player->dir_x > -1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 50, 30 + 50);
	}
}

void	tile_e(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_y > 0.66)
	{
		if (player->dir_x > -0.33 && player->dir_x < 0.33)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 58, 30 + 54);
		if (player->dir_x > 0.33 && player->dir_x < 0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 58, 30 + 56);
		if (player->dir_x > 0.66 && player->dir_x < 1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 58, 30 + 58);
		if (player->dir_x < -0.33 && player->dir_x > -0.66)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 58, 30 + 52);
		if (player->dir_x < -0.66 && player->dir_x > -1)
			mlx_put_image_to_window(cub3d->connection, cub3d->window,
				cub3d->minimap->dir->img_ptr, SCREEN_X - 140 + 58, 30 + 50);
	}
}
