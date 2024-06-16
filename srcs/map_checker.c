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

static void	get_biggest_column(char **map, t_cub3d *cub3D);
static void	count_map_rows(char **data_file, t_cub3d *cub3D);
static void	check_invalid_character(char **map, t_cub3d *cub3D);
static char	**extract_map_from_file(char **data_file, t_cub3d *cub3D);

void	map_checker(char **data_file, t_cub3d *cub3D)
{
	char	**map;
	char	**filled_map;

	count_map_rows(data_file, cub3D);
	map = extract_map_from_file(data_file, cub3D);
	get_biggest_column(map, cub3D);
	free_splits(data_file);
	check_invalid_character(map, cub3D);
	filled_map = padding_map(map, cub3D);
	free_splits(map);
	find_player_position(cub3D, filled_map);
	cub3D->map->f_map = extract_map_to_struct(filled_map, cub3D);
	if (!is_valid_map(filled_map, cub3D,
			cub3D->map->p_position[0], cub3D->map->p_position[1]))
	{
		free_splits(filled_map);
		p_error(INVALID_MAP, cub3D);
	}
	free_splits(filled_map);
}

static void	count_map_rows(char **data_file, t_cub3d *cub3D)
{
	int	i;

	i = -1;
	while (data_file[++i])
	{
		if (i >= cub3D->map->start_map)
			cub3D->map->rows++;
	}
}

static char	**extract_map_from_file(char **data_file, t_cub3d *cub3D)
{
	int		i;
	int		row;
	char	**map;

	i = -1;
	row = 0;
	map = ft_calloc(sizeof(char *), cub3D->map->rows + 1);
	if (!map)
		return (NULL);
	while (data_file[++i])
	{
		if (i >= cub3D->map->start_map)
		{
			map[row] = ft_strdup(data_file[i]);
			row++;
		}
	}
	return (map);
}

static void	get_biggest_column(char **map, t_cub3d *cub3D)
{
	int	i;
	int	j;
	int	columns;

	i = -1;
	columns = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (j >= columns)
				columns = j;
		}
	}
	cub3D->map->columns = columns;
}

static void	check_invalid_character(char **map, t_cub3d *cub3D)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '\n'
			&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
			&& map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E')
			{
				free_splits(map);
				p_error(INVALID_MAP, cub3D);
			}
		}
	}
}
