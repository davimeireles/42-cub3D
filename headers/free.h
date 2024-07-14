/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:14:30 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/04 17:28:34 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "cub3d.h"
/*
███████ ██████  ███████ ███████         ███    ███ ██      ██   ██
██      ██   ██ ██      ██              ████  ████ ██       ██ ██
█████   ██████  █████   █████           ██ ████ ██ ██        ███
██      ██   ██ ██      ██              ██  ██  ██ ██       ██ ██
██      ██   ██ ███████ ███████ ███████ ██      ██ ███████ ██   ██
*/

/**
 * @brief Free memory from mlx scenes.
 *
 * @param cub3D Struct containing all the parameters for the program.
 */
void	free_mlx(t_cub3d *cub3D);

/**
 * @brief Will freed the memory from the struct t_cub3d passed by parameter.
 *
 * @param cub3D Struct containing all the parameters for the program.
 */
void	free_memory(t_cub3d *cub3D);

/**
 * @brief Will split the *array[] passed by parameter.
 *
 * @param split *array[] with the info to be freed.
 */
void	free_splits(char **split);

#endif