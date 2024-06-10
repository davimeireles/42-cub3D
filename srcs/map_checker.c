/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:03:06 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/10 18:03:06 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *input);
static char **fill_map(char *input, int rows);

static int	count_lines(char *input)
{
	int		fd;
	int		rows;
	char	*line;
	char 	*t_line;

	fd = open(input, O_RDONLY);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		t_line = ft_strtrim(line, " ");
		if (t_line[0] == '1')
			rows++;
		free(line);
		free(t_line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

static char **fill_map(char *input, int rows) {
	char **map;
	char *line;
	int fd;

	map = ft_calloc(sizeof(char *), rows);
	if (map)
		p_error(MEMORY);
	fd = open(input, O_RDONLY);
	line = get_next_line(fd);
	while (line) {
	}
}

void	check_map(char *input)
{
	int rows;
	t_cub3d *cub3D;

	rows = 0;
	rows = count_lines(input);
	cub3D->map->map = fill_map(input, rows);
}

/*
static void	parsing_map(int fd)
{
	void	flood_fill(char **map, int i, int j)
	{
		if (map[i][j] == '1' || map[i][j] == 'G')
			return ;
		map[i][j] = 'G';
		flood_fill(map, i + 1, j);
		flood_fill(map, i - 1, j);
		flood_fill(map, i, j + 1);
		flood_fill(map, i, j - 1);
}


