/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/12 15:35:23 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_loader(t_cub3d *cub3d)
{
	background_loader(cub3d);
	raycaster(cub3d);
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->screen->screen->img_ptr, 0, 0);
	minimap_loader(cub3d);
}

void    background_loader(t_cub3d *cub3d)
{
	ft_pixelset(cub3d->screen->screen->data, cub3d->screen->ceiling, HALF_XY);
	ft_pixelset(&cub3d->screen->screen->data[HALF_XY], cub3d->screen->floor, HALF_XY);
}

void	minimap_loader(t_cub3d *cub3d)
{
	int 		mm_x;
	int 		mm_y;
	t_player	*player;
	
	player = cub3d->player;
	mm_x = -2;
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->minimap->bkg->img_ptr, SCREEN_X - 135, 25);
	while (mm_x <= 2)
	{
		mm_y = -2;
		while (mm_y <= 2)
		{
			print_tile(cub3d, (int) cub3d->player->y + mm_y, (int) cub3d->player->x + mm_x, mm_y, mm_x);
			mm_y++;
		}
		mm_x++;
	}
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->minimap->player->img_ptr, SCREEN_X - 135 + 50, 25 + 50);

	if (player->dir_x < -0.66 )
	{
		if (player->dir_y > -0.33 && player->dir_y < 0.33)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 54, 25 + 50); //N
		if (player->dir_y > 0.33 && player->dir_y < 0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 56, 25 + 50); //NNE
		if (player->dir_y > 0.66 && player->dir_y < 1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 58, 25 + 50); //NE
		if (player->dir_y < -0.33 && player->dir_y > -0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 52, 25 + 50); //NNW
		if (player->dir_y < -0.66 && player->dir_y > -1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 50, 25 + 50); //NW
	}
	if (player->dir_x > 0.66)
	{
		if (player->dir_y > -0.33 && player->dir_y < 0.33)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 54, 25 + 58); //S
		if (player->dir_y > 0.33 && player->dir_y < 0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 56, 25 + 58); //SSE
		if (player->dir_y > 0.66 && player->dir_y < 1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 58, 25 + 58); //SE
		if (player->dir_y < -0.33 && player->dir_y > -0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 52, 25 + 58); //SSW
		if (player->dir_y < -0.66 && player->dir_y > -1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 50, 25 + 58); //SW
	}
	if (player->dir_y < -0.66)
	{
		if (player->dir_x > -0.33 && player->dir_x < 0.33)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 50, 25 + 54); //W
		if (player->dir_x > 0.33 && player->dir_x < 0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 50, 25 + 56); //WNW
		if (player->dir_x > 0.66 && player->dir_x < 1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 50, 25 + 58); //NW
		if (player->dir_x < -0.33 && player->dir_x > -0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 50, 25 + 52); //WSW
		if (player->dir_x < -0.66 && player->dir_x > -1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 50, 25 + 50); //SW
		
	}
	if (player->dir_y > 0.66)
	{
		if (player->dir_x > -0.33 && player->dir_x < 0.33)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 58, 25 + 54); //E
		if (player->dir_x > 0.33 && player->dir_x < 0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 58, 25 + 56); //ENE
		if (player->dir_x > 0.66 && player->dir_x < 1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 58, 25 + 58); //NE
		if (player->dir_x < -0.33 && player->dir_x > -0.66)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 58, 25 + 52); //ESE
		if (player->dir_x < -0.66 && player->dir_x > -1)
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->dir->img_ptr, SCREEN_X - 135 + 58, 25 + 50); //SE
	}
}
