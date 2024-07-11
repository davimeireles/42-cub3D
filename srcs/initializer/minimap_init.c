/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:51 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/11 22:05:40 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

static void	create_minimap(t_cub3d *cub3d);

void	minimap_init(t_cub3d *cub3d)
{
    cub3d->minimap->bkg = ft_calloc(sizeof(t_img), 1);
    cub3d->minimap->floor = ft_calloc(sizeof(t_img), 1);
    cub3d->minimap->wall = ft_calloc(sizeof(t_img), 1);
    cub3d->minimap->player = ft_calloc(sizeof(t_img), 1);
    cub3d->minimap->dir = ft_calloc(sizeof(t_img), 1);
	create_minimap(cub3d);
    ft_pixelset(cub3d->minimap->bkg->data, BLACK, 110 * 110);
    ft_pixelset(cub3d->minimap->floor->data, WHITE, 20 * 20);
    ft_pixelset(cub3d->minimap->wall->data, GREY, 20 * 20);
    ft_pixelset(cub3d->minimap->player->data, RED, 10 * 10);
    ft_pixelset(cub3d->minimap->dir->data, GREEN, 2 * 2);
}

static void	create_minimap(t_cub3d *cub3d)
{
	t_img   *bkg;
	t_img   *floor;
	t_img   *wall;
	t_img   *player;
    t_img   *dir;

	bkg = cub3d->minimap->bkg;
	floor = cub3d->minimap->floor;
	wall = cub3d->minimap->wall;
	player = cub3d->minimap->player;
    dir = cub3d->minimap->dir;
	bkg->img_ptr = mlx_new_image(cub3d->connection, 110, 110);
	floor->img_ptr = mlx_new_image(cub3d->connection, 20, 20);
	wall->img_ptr = mlx_new_image(cub3d->connection, 20, 20);
	player->img_ptr = mlx_new_image(cub3d->connection, 10, 10);
    dir->img_ptr = mlx_new_image(cub3d->connection, 2, 2);
	bkg->data = (int *) mlx_get_data_addr(bkg->img_ptr, &bkg->bits_per_pixel,
        &bkg->size_line, &bkg->endian);
    floor->data = (int *) mlx_get_data_addr(floor->img_ptr, &floor->bits_per_pixel,
        &floor->size_line, &floor->endian);
    wall->data = (int *) mlx_get_data_addr(wall->img_ptr, &wall->bits_per_pixel,
        &wall->size_line, &wall->endian);
    player->data = (int *) mlx_get_data_addr(player->img_ptr, &player->bits_per_pixel,
        &player->size_line, &player->endian);
    dir->data = (int *) mlx_get_data_addr(dir->img_ptr, &dir->bits_per_pixel,
        &dir->size_line, &dir->endian);
}