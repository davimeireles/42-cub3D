/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:13:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/15 16:44:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_memory(t_cub3d *cub3D)
{
	if (cub3D->map->textures->flood)
		free(cub3D->map->textures->flood);
	if (cub3D->map->textures)
		free(cub3D->map->textures);
	if (cub3D->map->f_map)
		free_splits(cub3D->map->f_map);
	free(cub3D->map->north);
	free(cub3D->map->south);
	free(cub3D->map->east);
	free(cub3D->map->west);
	free(cub3D->map->floor);
	free(cub3D->map->ceiling);
	free(cub3D->map);
	free(cub3D);
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
