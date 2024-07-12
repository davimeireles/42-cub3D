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
	int	j;

	i = -1;

	cub3D->map->textures->flood->visited = ft_calloc(sizeof(bool *),
			cub3D->map->rows);
	while (++i < cub3D->map->rows)
	{
		cub3D->map->textures->flood->visited[i] = ft_calloc(sizeof(bool),
				cub3D->map->columns);
		j = -1;
		while (++j < cub3D->map->columns)
			cub3D->map->textures->flood->visited[i][j] = false;
	}
	return (is_valid_map(map, cub3D));
}

bool	is_valid_map(char **map, t_cub3d *cub3D)
{
	int	x;

	int	y;
	int	i;

	x = -1;
	while (++x < cub3D->map->rows)
	{
		y = -1;
		while (++y <= cub3D->map->columns)
		{
			if (map[x][y] == '0' || map[x][y] == 'N'
				|| map[x][y] == 'S' || map[x][y] == 'E'
				|| map[x][y] == 'W' || map[x][y] == 'x')
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
