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

static int	find_biggest_column(char **map);
static void	map_padding(char **map, int	biggest_column);
static void	find_player_position(t_cub3d *cub3D);
static bool	is_valid_map(t_cub3d *cub3D, int x, int y);

void	map_checker(t_cub3d *cub3D)
{
	cub3D->map->columns = find_biggest_column(cub3D->map->f_map);
	map_padding(cub3D->map->f_map,cub3D->map->columns);
	find_player_position(cub3D);
	// need to send a copy of the map to not change the main map
	if(!is_valid_map(cub3D, cub3D->map->p_position[0], cub3D->map->p_position[1]))
		p_error(INVALID_MAP);
}

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
	if (count > 1 || count == 0)
	{
		free_memory(cub3D);
		p_error(INVALID_MAP);
	}
}

static bool	is_valid_map(t_cub3d *cub3D, int x, int y)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (x < 0 || x >= cub3D->map->rows - 1 || y < 0 || y >= cub3D->map->columns)
		return false;
	if (cub3D->map->f_map[x][y] == '1' || cub3D->map->f_map[x][y] == 'P')
		return true;
	if (x == 0 || x == cub3D->map->rows - 1 || y == 0 || y == cub3D->map->columns)
		return false;
	cub3D->map->f_map[x][y] = 'P';
	up = is_valid_map(cub3D, x - 1, y);
	down = is_valid_map(cub3D, x + 1, y);
	left = is_valid_map(cub3D, x, y - 1);
	right = is_valid_map(cub3D, x, y + 1);
	return (up && down && left && right);
}
