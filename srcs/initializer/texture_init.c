/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:47:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/12 17:06:54 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	screen_init(t_cub3d *cub3D);
static void	load_texture(t_cub3d *cub3d);

void	init_textures(t_cub3d * cub3d)
{
	screen_init(cub3d);
	load_texture(cub3d);
}

static void	screen_init(t_cub3d *cub3d)
{
	cub3d->screen->ceiling = get_color(cub3d->map->ceiling);
	cub3d->screen->floor = get_color(cub3d->map->floor);
	cub3d->screen->height = SCREEN_Y;
	cub3d->screen->width = SCREEN_X;
	cub3d->screen->screen = ft_calloc(1, sizeof(t_img));
	cub3d->screen->screen->img_ptr = mlx_new_image(cub3d->connection,
		cub3d->screen->width, cub3d->screen->height);
	cub3d->screen->screen->data = (int *)mlx_get_data_addr(cub3d->screen->screen->img_ptr,
		&cub3d->screen->screen->bits_per_pixel, &cub3d->screen->screen->size_line,
		&cub3d->screen->screen->endian);
}

t_img	*load_image(t_cub3d *cub3d, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	path[ft_strlen(path) - 1] = '\0';
	img->img_ptr = mlx_xpm_file_to_image(cub3d->connection, path, &img->width, &img->height);
	if (img->img_ptr)
	{
		img->data = (int *) mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	}
	return (img);
}

static void	load_texture(t_cub3d *cub3d)
{
	cub3d->screen->north = load_image(cub3d, cub3d->map->north);
	cub3d->screen->south = load_image(cub3d, cub3d->map->south);
	cub3d->screen->east = load_image(cub3d, cub3d->map->east);
	cub3d->screen->west = load_image(cub3d, cub3d->map->west);
	if (!cub3d->screen->north->img_ptr || !cub3d->screen->south->img_ptr ||
		!cub3d->screen->east->img_ptr || !cub3d->screen->west->img_ptr)
		p_error(TEXTURES, cub3d);
}