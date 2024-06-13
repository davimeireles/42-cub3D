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
static void find_player_position(t_cub3d *cub3D);

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
	int		i;
	int		j;
	char	*new_line;

	i = -1;
	while (map[++i])
	{
		new_line = ft_calloc(sizeof(char), biggest_column + 1);
		if (!new_line)
			p_error(MEMORY);
		j = -1;
		if (new_line)
		{
			if (biggest_column > 0)
				new_line[biggest_column - 1] = '\n';
			new_line[biggest_column] = '\0';
			while (++j < biggest_column)
			{
				if (map[i][j])
				{
					if (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
						new_line[j] = 'x';
					else
						new_line[j] = map[i][j];
				}
				else
				{
					while (j < biggest_column)
						new_line[j++] = 'x';
					break;
				}
			}
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
	find_player_position(cub3D);
}

static void find_player_position(t_cub3d *cub3D)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (cub3D->map->f_map[++i])
	{
		j = -1;
		while (cub3D->map->f_map[i][++j])
		{
			if (cub3D->map->f_map[i][j] == 'N' || cub3D->map->f_map[i][j] == 'S'
			|| cub3D->map->f_map[i][j] == 'E' || cub3D->map->f_map[i][j] == 'W')
			{
				count++;
				cub3D->map->p_position[0] = i;
				cub3D->map->p_position[1] = j;
			}
		}
	}
	if (count > 1)
	{
		free_memory(cub3D);
		p_error(INVALID_MAP);
	}
}


/*
void	flood_fill(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'G')
		return ;
	map[i][j] = 'G';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}*/
