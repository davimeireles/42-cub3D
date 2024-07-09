/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:33:42 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/08 21:22:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void    raycasting(t_cub3d *cub3d, int x);

void    raycaster(t_cub3d *cub3d)
{
    int x;

    x = 0;
    while (x < 1280)
    {
        raycasting(cub3d, x);
        x++;
    }
}

void    raycasting(t_cub3d *cub3d, int x)
{
    (void)cub3d;
    (void)x;
}