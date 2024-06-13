/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:43:19 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/12 12:43:19 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_padding(char **map, int	biggest_column);
static int	find_biggest_column(char **map);

static int find_biggest_column(char **map)
{
	int i;
	int c;
	int big;

	i = -1;
	big = 0;
	while (map[++i])
	{
		c = -1;
		while(map[i][++c])
		{
			if (c >= big)
				big = c;
		}
	}
	return (big);
}

static void	map_padding(char **map, int biggest_column)
{
	int i;
	int j;
	char *new_line;

	i = -1;
	while (map[++i])
	{
		new_line = ft_calloc(sizeof(char), biggest_column);
		if (!new_line)
			p_error(MEMORY);
		j = -1;
		while (++j <= biggest_column)
		{
			if (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n' || map[i][j] == '\0')
				new_line[j] = 'x';
			else if (j == biggest_column)
				new_line[j] = '\n';
			else
				new_line[j] = map[i][j];
		}
		free(map[i]);
		map[i] = ft_strdup(new_line);
		free(new_line);
	}
}

void	map_checker(t_cub3d *cub3D)
{
	int	biggest_column;

	biggest_column = 0;
	biggest_column = find_biggest_column(cub3D->map->f_map);
	map_padding(cub3D->map->f_map, biggest_column);
}