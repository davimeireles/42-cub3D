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


static char **padding_map(char **map, t_cub3d *cub3D);
static void get_biggest_column(char **map, t_cub3d *cub3D);
static void	count_map_rows(char **data_file, t_cub3d *cub3D);
static char	*padding_aux(char *map, char *line, t_cub3d *cub3D);
static void	check_invalid_character(char **map, t_cub3d *cub3D);
static bool	is_valid_map(char **map, t_cub3d *cub3D, int x, int y);
static void find_player_position(t_cub3d *cub3D, char **filled_map);
static char **extract_map_from_file(char **data_file, t_cub3d *cub3D);
static char	**extract_map_to_struct(char **map, t_cub3d *cub3D);


void	map_checker(char **data_file, t_cub3d *cub3D)
{

	char	**map;
	char 	**filled_map;

	count_map_rows(data_file, cub3D);
	map = extract_map_from_file(data_file, cub3D);
	get_biggest_column(map, cub3D);
	free_splits(data_file);
	check_invalid_character(map, cub3D);
	filled_map = padding_map(map, cub3D);
	free_splits(map);
	find_player_position(cub3D, filled_map);
	cub3D->map->f_map = extract_map_to_struct(filled_map, cub3D);
	if (!is_valid_map(filled_map, cub3D, cub3D->map->p_position[0], cub3D->map->p_position[1]))
	{
		free_splits(filled_map);
		p_error(INVALID_MAP, cub3D);
	}
	free_splits(filled_map);
}

static void	count_map_rows(char **data_file, t_cub3d *cub3D)
{
	int i;

	i = -1;
	while (data_file[++i])
	{
		if (i >= cub3D->map->start_map)
			cub3D->map->rows++;
	}
}

static char **extract_map_from_file(char **data_file, t_cub3d *cub3D)
{
	int 	i;
	int 	row;
	char	**map;


	i = -1;
	row = 0;
	map = ft_calloc(sizeof(char *), cub3D->map->rows + 1);
	if (!map) {
		return (NULL);
	}
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

static void get_biggest_column(char **map, t_cub3d *cub3D)
{
	int i;
	int j;
	int columns;

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
	int i;
	int j;

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

static char **padding_map(char **map, t_cub3d *cub3D)
{
	int		i;
	char	*new_line;
	char	**filled_map;

	filled_map = ft_calloc(sizeof(char *), cub3D->map->rows + 1);
	if (!filled_map)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		new_line = ft_calloc(sizeof(char), cub3D->map->columns + 1);
		if (!new_line)
			return (NULL);
		new_line[cub3D->map->columns] = '\0';
		new_line = padding_aux(map[i], new_line, cub3D);
		filled_map[i] = ft_strdup(new_line);
		free(new_line);
	}
	return (filled_map);
}

static char	*padding_aux(char *map, char *line, t_cub3d *cub3D)
{
	int j;
	int i;

	j = -1;
	i = 0;
	while (++j < cub3D->map->columns)
	{
		if (map[j])
		{
			if (map[j] == ' ' || map[j] == '\t' || map[j] == '\n' || map[j] == '\0')
				line[i] = 'x';
			else
				line[i] = map[j];
		}
		else
		{
			while (j < cub3D->map->columns)
				line[j++] = 'x';
			break ;
		}
		i++;
	}
	return (line);
}

static void find_player_position(t_cub3d *cub3D, char **filled_map)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (filled_map[++i])
	{
		j = -1;
		while (filled_map[i][++j])
		{
			if (filled_map[i][j] == 'N' || filled_map[i][j] == 'S'
			|| filled_map[i][j] == 'E' || filled_map[i][j] == 'W')
			{
				count++;
				cub3D->map->p_position[0] = i;
				cub3D->map->p_position[1] = j;
			}
		}
	}
	if (count > 1 || count == 0)
	{
		free_splits(filled_map);
		p_error(INVALID_MAP, cub3D);
	}
}

static char **extract_map_to_struct(char **map, t_cub3d *cub3D)
{
	int i;
	char **new_map;

	i = -1;
	new_map = ft_calloc(sizeof(char *), cub3D->map->rows + 1);
	if (!new_map)
		return (NULL);
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	return (new_map);
}

static bool	is_valid_map(char **map, t_cub3d *cub3D, int x, int y)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (x < 0 || x >= cub3D->map->rows - 1 || y < 0 || y >= cub3D->map->columns)
		return false;
	if (map[x][y] == '1' || map[x][y] == 'P')
		return true;
	if (x == 0 || x == cub3D->map->rows - 1 || y == 0 || y == cub3D->map->columns)
		return false;
	map[x][y] = 'P';
	up = is_valid_map(map, cub3D, x - 1, y);
	down = is_valid_map(map, cub3D, x + 1, y);
	left = is_valid_map(map, cub3D, x, y - 1);
	right = is_valid_map(map, cub3D, x, y + 1);
	return (up && down && left && right);
}
