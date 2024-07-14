/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:51 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 20:20:07 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_minimap(t_cub3d *cub3d);
static void	ft_img_data(t_img *img);

void	minimap_init(t_cub3d *cub3d)
{
	cub3d->minimap->bkg = ft_calloc(sizeof(t_img), 1);
	cub3d->minimap->floor = ft_calloc(sizeof(t_img), 1);
	cub3d->minimap->wall = ft_calloc(sizeof(t_img), 1);
	cub3d->minimap->player = ft_calloc(sizeof(t_img), 1);
	cub3d->minimap->dir = ft_calloc(sizeof(t_img), 1);
	create_minimap(cub3d);
	ft_pixelset(cub3d->minimap->bkg->data, BLACK, 120 * 120);
	ft_pixelset(cub3d->minimap->floor->data, WHITE, 10 * 10);
	ft_pixelset(cub3d->minimap->wall->data, GREY, 10 * 10);
	ft_pixelset(cub3d->minimap->player->data, RED, 10 * 10);
	ft_pixelset(cub3d->minimap->dir->data, GREEN, 2 * 2);
}

static void	create_minimap(t_cub3d *cub3d)
{
	t_img	*bkg;
	t_img	*floor;
	t_img	*wall;
	t_img	*player;
	t_img	*dir;

	bkg = cub3d->minimap->bkg;
	floor = cub3d->minimap->floor;
	wall = cub3d->minimap->wall;
	player = cub3d->minimap->player;
	dir = cub3d->minimap->dir;
	bkg->img_ptr = mlx_new_image(cub3d->connection, 120, 120);
	floor->img_ptr = mlx_new_image(cub3d->connection, 10, 10);
	wall->img_ptr = mlx_new_image(cub3d->connection, 10, 10);
	player->img_ptr = mlx_new_image(cub3d->connection, 10, 10);
	dir->img_ptr = mlx_new_image(cub3d->connection, 2, 2);
	ft_img_data(bkg);
	ft_img_data(floor);
	ft_img_data(wall);
	ft_img_data(player);
	ft_img_data(dir);
}

static void	ft_img_data(t_img *img)
{
	img->data = (int *) mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
}
