/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 05:31:24 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/17 18:53:49 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	flood_fill_recursive(char **map, t_cub3d *cub3D, int x, int y);

bool	flood_fill(char **map, t_cub3d *cub3D, int x, int y)
{
	if (x < 0 || x >= cub3D->map->rows || y < 0 || y >= cub3D->map->columns
		|| map[x][y] == '\0' || map[x][y] == '\n')
		return (false);
	if (map[x][y] == '1' || cub3D->map->textures->flood->visited[x][y])
		return (true);
	if (map[x][y] == ' ' || map[x][y] == '\t')
		return (false);
	cub3D->map->textures->flood->visited[x][y] = true;
	return (flood_fill_recursive(map, cub3D, x, y));
}

static bool	flood_fill_recursive(char **map, t_cub3d *cub3D, int x, int y)
{
	bool	u;
	bool	d;
	bool	l;
	bool	r;

	if ((x > 0 && (map[x - 1][y] == ' ' || map[x - 1][y] == '\t')) ||
		(x < cub3D->map->rows - 1 &&
		(map[x + 1][y] == ' ' || map[x + 1][y] == '\t')) ||
		(y > 0 && (map[x][y - 1] == ' ' || map[x][y - 1] == '\t')) ||
		(y < cub3D->map->columns - 1 && (map[x][y + 1] == ' '
		|| map[x][y + 1] == '\t')))
		return (false);
	u = flood_fill(map, cub3D, x - 1, y);
	d = flood_fill(map, cub3D, x + 1, y);
	l = flood_fill(map, cub3D, x, y - 1);
	r = flood_fill(map, cub3D, x, y + 1);
	return (u && d && l && r);
}

void	find_player_position(t_cub3d *cub3D, char **filled_map, int i)
{
	int	j;
	int	count;

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
				cub3D->map->p_direction = filled_map[i][j];
			}
		}
	}
	if (count > 1 || count == 0)
	{
		free_splits(filled_map);
		p_error(INVALID_MAP, cub3D);
	}
}

void	fill_textures_info(char **data_file, t_cub3d *cub3D)
{
	int		i;
	char	**s_line;
	char	*trimmed;

	i = -1;
	while (data_file[++i])
	{
		trimmed = trim_spaces_around_commas(data_file[i]);
		s_line = ft_split(trimmed, ' ');
		if (!ft_strcmp(s_line[0], "NO"))
			cub3D->map->north = ft_strdup(s_line[1]);
		else if (!ft_strcmp(s_line[0], "SO"))
			cub3D->map->south = ft_strdup(s_line[1]);
		else if (!ft_strcmp(s_line[0], "WE"))
			cub3D->map->west = ft_strdup(s_line[1]);
		else if (!ft_strcmp(s_line[0], "EA"))
			cub3D->map->east = ft_strdup(s_line[1]);
		else if (!ft_strcmp(s_line[0], "C"))
			cub3D->map->ceiling = ft_strdup(s_line[1]);
		else if (!ft_strcmp(s_line[0], "F"))
			cub3D->map->floor = ft_strdup(s_line[1]);
		free(trimmed);
		free_splits(s_line);
	}
}
