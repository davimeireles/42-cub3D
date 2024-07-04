/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:13:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/04 17:27:57 by txisto-d         ###   ########.fr       */
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

void	free_memory(t_cub3d *cub3D)
{
	if (cub3D)
	{
		if (cub3D->map)
		{
			if (cub3D->map->textures->flood)
				free(cub3D->map->textures->flood);
			if (cub3D->map->textures)
				free(cub3D->map->textures);
			if (cub3D->map->f_map)
				free_splits(cub3D->map->f_map);
			if (cub3D->map->text_imgs)
				free(cub3D->map->text_imgs);
			free(cub3D->map->north);
			free(cub3D->map->south);
			free(cub3D->map->east);
			free(cub3D->map->west);
			free(cub3D->map->floor);
			free(cub3D->map->ceiling);
			free(cub3D->map);
		}
		free(cub3D);
	}
}

void	free_splits(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free (split);
	}
}