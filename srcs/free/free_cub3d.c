/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:47:32 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/16 16:20:13 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_img(t_img *image, t_cub3d *cub3d);
static void	free_minimap(t_cub3d *cub3d);
static void	free_screen(t_cub3d *cub3d);

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->player)
		free(cub3d->player);
	if (cub3d->raycaster)
		free(cub3d->raycaster);
	if (cub3d->minimap)
		free_minimap(cub3d);
	if (cub3d->screen)
		free_screen(cub3d);
	if (cub3d->window)
		mlx_destroy_window(cub3d->connection, cub3d->window);
	free(cub3d->timer->tv);
	free(cub3d->timer);
	if (cub3d->connection)
	{
		mlx_destroy_display(cub3d->connection);
		free(cub3d->connection);
	}
	if (cub3d->map)
		free_memory(cub3d);
}

static void	free_minimap(t_cub3d *cub3d)
{
	if (cub3d->minimap->bkg)
		free_img(cub3d->minimap->bkg, cub3d);
	if (cub3d->minimap->player)
		free_img(cub3d->minimap->player, cub3d);
	if (cub3d->minimap->wall)
		free_img(cub3d->minimap->wall, cub3d);
	if (cub3d->minimap->floor)
		free_img(cub3d->minimap->floor, cub3d);
	if (cub3d->minimap->dir)
		free_img(cub3d->minimap->dir, cub3d);
	free(cub3d->minimap);
}

static void	free_screen(t_cub3d *cub3d)
{
	if (cub3d->screen->north)
		free_img(cub3d->screen->north, cub3d);
	if (cub3d->screen->east)
		free_img(cub3d->screen->east, cub3d);
	if (cub3d->screen->south)
		free_img(cub3d->screen->south, cub3d);
	if (cub3d->screen->west)
		free_img(cub3d->screen->west, cub3d);
	if (cub3d->screen->screen)
		free_img(cub3d->screen->screen, cub3d);
	free(cub3d->screen);
}

static void	free_img(t_img *image, t_cub3d *cub3d)
{
	if (image->img_ptr)
		mlx_destroy_image(cub3d->connection, image->img_ptr);
	free(image);
}
