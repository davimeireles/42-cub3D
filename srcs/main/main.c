/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:57 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/08 20:29:55 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc == 2)
	{
		initialize_cub(&cub3d);
		check_map_name(argv[1], cub3d);
		check_file_config(argv[1], cub3d);
		print_colored_matrix(cub3d->map->f_map);
		window_init(cub3d);
		player_init(cub3d);
		init_textures(cub3d);
		minimap_init(cub3d);
		screen_loader(cub3d);
		game_init(cub3d);
	}
	else
		p_error(N_ARGS, NULL);
	return (0);
}
