/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:30:07 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/08 20:29:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "cub3d.h"

/*
███████  ██████ ██████  ███████ ███████ ███    ██ 
██      ██      ██   ██ ██      ██      ████   ██ 
███████ ██      ██████  █████   █████   ██ ██  ██ 
     ██ ██      ██   ██ ██      ██      ██  ██ ██ 
███████  ██████ ██   ██ ███████ ███████ ██   ████ 
*/

/**
 * @brief Load the screen.
 */
void	screen_loader(t_cub3d *cub3d);

/**
 * @brief Load the background image.
 */
void	background_loader(t_cub3d *cub3d);

/**
 * @brief Load the minimap.
 */
void	minimap_loader(t_cub3d *cub3d);
#endif