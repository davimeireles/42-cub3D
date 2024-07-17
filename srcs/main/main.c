/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:57 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/17 16:36:20 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_controls(void)
{
	printf("\n");
	printf("\t░█▀▀░█░█░█▀▄░▀▀█░█▀▄░\n");
	printf("\t░█░░░█░█░█▀▄░░▀▄░█░█░\n");
	printf("\t░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░\n");
	printf("\n");
	printf("\tW" ": move forward\t");
	printf("\tS" ": move backward\n");
	printf("\tA" ": strafe left\t");
	printf("\tD" ": strafe right\n");
	printf("\t<" ": rotate left\t");
	printf("\t>" ": rotate right\n");
	printf("\tMouse" ": rotate view\n");
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc == 2)
	{
		initialize_cub(&cub3d);
		check_map_name(argv[1], cub3d);
		check_file_config(argv[1], cub3d);
		window_init(cub3d);
		player_init(cub3d);
		init_textures(cub3d);
		print_colored_matrix(cub3d->map->f_map);
		minimap_init(cub3d);
		game_init(cub3d);
		print_controls();
		mlx_loop_hook(cub3d->connection, screen_loader, cub3d);
		mlx_loop(cub3d->connection);
		free_cub3d(cub3d);
	}
	else
		p_error(N_ARGS, NULL);
	return (0);
}
