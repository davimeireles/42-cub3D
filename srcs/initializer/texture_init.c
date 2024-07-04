/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:47:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/04 23:36:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	background_init(t_cub3d *cub3D);
static void	cf_init(t_cub3d *cub3d, t_img *image, char *color);

void    init_textures(t_cub3d * cub3d)
{
	background_init(cub3d);
	background_loader(cub3d);
}

static void	background_init(t_cub3d *cub3d)
{
	cub3d->screen->heigh = SCREEN_Y;
	cub3d->screen->width = SCREEN_X;
	cub3d->screen->ceiling = ft_calloc(1, sizeof(t_img));
	cub3d->screen->floor = ft_calloc(1, sizeof(t_img));
	cf_init(cub3d, cub3d->screen->ceiling, cub3d->map->ceiling);
	cf_init(cub3d, cub3d->screen->floor, cub3d->map->floor);
}

static void	cf_init(t_cub3d *cub3d, t_img *image, char *color)
{
	int		color_int;
	

	color_int = get_color(color);
	image->img_ptr = mlx_new_image(cub3d->connection, cub3d->screen->width, cub3d->screen->heigh / 2);
	image->data = mlx_get_data_addr(image->img_ptr, &image->bits_per_pixel, &image->size_line, &image->endian);
	ft_pixelset(image->data, color_int, (cub3d->screen->width * cub3d->screen->heigh / 2));
}

t_img	load_texture(void *mlx, char *path, t_cub3d *cub3D)
{
	t_img	texture;
	int		bpp;
	int		size_line;
	int		endian;

	texture.img_ptr = mlx_xpm_file_to_image(mlx, path, &texture.width, &texture.height);
	if (!texture.img_ptr)
	{
		free(cub3D->connection);
		free_mlx(cub3D);
		exit(EXIT_FAILURE);
	}
	texture.data = mlx_get_data_addr(texture.img_ptr, &bpp, &size_line, &endian);
	return (texture);
}
