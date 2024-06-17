/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:58:09 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/16 17:58:09 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool flood_fill(char **map, t_cub3d *cub3D, int x, int y);

void	check_map_name(char *input, t_cub3d *cub3d)
{
	int		fd;
	size_t	i;

	i = ft_strlen(input);
	if (!(input[i - 1] == 'b' && input[i - 2] == 'u'
			&& input[i - 3] == 'c' && input[i - 4] == '.'
			&& input[i - 5]))
		p_error(MAP_NAME, cub3d);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		p_error(OPEN_ERROR, cub3d);
	count_file_rows(fd, cub3d->map->textures);
	close(fd);
}

char	**padding_map(char **map, t_cub3d *cub3D)
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

void	find_player_position(t_cub3d *cub3D, char **filled_map)
{
	int	i;
	int	j;
	int	count;

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

char	**extract_map_to_struct(char **map, t_cub3d *cub3D)
{
	int		i;
	char	**new_map;

	i = -1;
	new_map = ft_calloc(sizeof(char *), cub3D->map->rows + 1);
	if (!new_map)
		return (NULL);
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	return (new_map);
}

bool	initialize_visited(char **map, t_cub3d *cub3D)
{
	int	i;
	int j;

	i = -1;
	cub3D->map->textures->flood->visited = ft_calloc(sizeof(bool *), cub3D->map->rows);
	while (++i < cub3D->map->rows)
	{
		cub3D->map->textures->flood->visited[i] = ft_calloc(sizeof(bool), cub3D->map->columns);
		j = -1;
		while (++j < cub3D->map->columns)
			cub3D->map->textures->flood->visited[i][j] = false;
	}
	return(is_valid_map(map, cub3D));
}

bool	is_valid_map(char **map, t_cub3d *cub3D)
{
	int x;
	int y;
	int i;

	x = -1;
	while (++x < cub3D->map->rows)
	{
		y = -1;
		while (++y <= cub3D->map->columns)
		{
			if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S' || map[x][y] == 'E' || map[x][y] == 'W' || map[x][y] == 'x')
			{
				if (!flood_fill(map, cub3D, x, y))
				{
					i = -1;
					while (++i < cub3D->map->rows)
						free(cub3D->map->textures->flood->visited[i]);
					free(cub3D->map->textures->flood->visited);
					return (false);
				}
			}
		}
	}
	i = -1;
	while (++i < cub3D->map->rows)
		free(cub3D->map->textures->flood->visited[i]);
	free(cub3D->map->textures->flood->visited);
	return (true);
}

bool flood_fill(char **map, t_cub3d *cub3D, int x, int y)
{
	if (x < 0 || x >= cub3D->map->rows || y < 0 || y >= cub3D->map->columns)
		return (false);
	if (map[x][y] == '1' || cub3D->map->textures->flood->visited[x][y])
		return (true);
	if (x == 0 || x == cub3D->map->rows
		|| y == 0 || y == cub3D->map->columns)
		return (false);
	cub3D->map->textures->flood->visited[x][y] = true;
	cub3D->map->textures->flood->u = flood_fill(map, cub3D, x - 1, y);
	cub3D->map->textures->flood->d = flood_fill(map, cub3D, x + 1, y);
	cub3D->map->textures->flood->l = flood_fill(map, cub3D, x, y - 1);
	cub3D->map->textures->flood->r = flood_fill(map, cub3D, x, y + 1);
	cub3D->map->textures->flood->u_l = flood_fill(map, cub3D,
													x - 1, y - 1);
	cub3D->map->textures->flood->u_r = flood_fill(map, cub3D,
													x - 1, y + 1);
	cub3D->map->textures->flood->d_l = flood_fill(map, cub3D,
													x + 1, y - 1);
	cub3D->map->textures->flood->d_r = flood_fill(map, cub3D,
													x + 1, y + 1);
	return (cub3D->map->textures->flood->u && cub3D->map->textures->flood->d
			&& cub3D->map->textures->flood->l && cub3D->map->textures->flood->r
			&& cub3D->map->textures->flood->u_l && cub3D->map->textures->flood->u_r
			&& cub3D->map->textures->flood->d_l
			&& cub3D->map->textures->flood->d_r);
}
