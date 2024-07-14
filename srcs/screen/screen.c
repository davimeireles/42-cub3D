/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 20:32:13 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tile_n(t_player *player, t_cub3d *cub3d);
void	tile_s(t_player *player, t_cub3d *cub3d);
void	tile_w(t_player *player, t_cub3d *cub3d);
void	tile_e(t_player *player, t_cub3d *cub3d);

int	screen_loader(t_cub3d *cub3d)
{
	background_loader(cub3d);
	raycaster(cub3d);
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->screen->screen->img_ptr, 0, 0);
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

void	tile_n(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_x < -0.66 )
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
