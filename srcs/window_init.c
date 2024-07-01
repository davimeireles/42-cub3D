/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:45:24 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/24 10:45:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_cub3d *cub3D)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (cub3D->map->text_imgs[i].img_ptr)
			mlx_destroy_image(cub3D->connection,
				cub3D->map->text_imgs[i].img_ptr);
	}
	if (cub3D->window)
		mlx_destroy_window(cub3D->connection, cub3D->window);
	if (cub3D->connection)
	{
		mlx_destroy_display(cub3D->connection);
		free(cub3D->connection);
	}
	free_memory(cub3D);
}

int	key_hook(int keycode, t_cub3d *cub3D)
{
	if (keycode == 65307)
	{
		mlx_loop_end(cub3D->connection);
		free_mlx(cub3D);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window_x(t_cub3d *cub3D)
{
	mlx_loop_end(cub3D->connection);
	free_mlx(cub3D);
	exit(EXIT_SUCCESS);
	return (0);
}

void	window_init(t_cub3d *cub3D)
{
	cub3D->connection = mlx_init();
	if (!cub3D->connection)
	{
		free_memory(cub3D);
		exit(EXIT_FAILURE);
	}
	cub3D->window = mlx_new_window(cub3D->connection, 1280, 720, "cub3d");
	if (!cub3D->window)
	{
		free(cub3D->connection);
		free_memory(cub3D);
		exit(EXIT_FAILURE);
	}
	cub3D->map->text_imgs[0] = load_texture(cub3D->connection, "textures/wolftex/bluestone.xpm", cub3D);
	cub3D->map->text_imgs[1] = load_texture(cub3D->connection, "textures/wolftex/colorstone.xpm", cub3D);
	cub3D->map->text_imgs[2] = load_texture(cub3D->connection, "textures/wolftex/greenlight.xpm", cub3D);
	cub3D->map->text_imgs[3] = load_texture(cub3D->connection, "textures/wolftex/greystone.xpm", cub3D);
	cub3D->map->text_imgs[4] = load_texture(cub3D->connection, "textures/wolftex/wood.xpm", cub3D);
	cub3D->map->text_imgs[5] = load_texture(cub3D->connection, "textures/wolftex/mossy.xpm", cub3D);
	mlx_key_hook(cub3D->window, key_hook, cub3D);
	mlx_hook(cub3D->window, 17, 0, (int (*)(void *))close_window_x, cub3D);
	mlx_loop(cub3D->connection);
	mlx_loop_end(cub3D->connection);
	free_mlx(cub3D);
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
	texture.data = (int *)mlx_get_data_addr(texture.img_ptr, &bpp, &size_line, &endian);
	return (texture);
}
