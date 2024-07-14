/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:01:52 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/14 06:01:19 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_has_configs(char **data_file, t_cub3d *cub3d);
static int	check_number_args_config(char **data_file, t_cub3d *cub3D,
				int i, int error);
static void	check_if_configs_above(char **data_file, t_cub3d *cub3D);
static void	check_rgb_config(char **data_file, char **s_line, t_cub3d *cub3D);

void	check_file_config(char *input, t_cub3d *cub3d)
{
	int		fd;
	char	**data_file;

	fd = open(input, O_RDONLY);
	data_file = pass_data_array(fd, cub3d->map->textures);
	close(fd);
	check_has_configs(data_file, cub3d);
	if (cub3d->map->textures->no != 1
		|| cub3d->map->textures->so != 1
		|| cub3d->map->textures->we != 1
		|| cub3d->map->textures->ea != 1
		|| cub3d->map->textures->f != 1
		|| cub3d->map->textures->c != 1)
	{
		free_splits(data_file);
		p_error(CONFIGS, cub3d);
	}
	if (check_number_args_config(data_file, cub3d, -1, 0))
	{
		free_splits(data_file);
		p_error(CONFIGS, cub3d);
	}
	check_if_configs_above(data_file, cub3d);
	cub3d->map->start_map = find_map_start(data_file);
	map_checker(data_file, cub3d);
}

static void	check_has_configs(char **data_file, t_cub3d *cub3d)
{
	int		i;
	char	**s_line;

	i = -1;
	while (data_file[++i])
	{
		s_line = ft_split(data_file[i], ' ');
		if (!ft_strcmp(s_line[0], "NO"))
			cub3d->map->textures->no++;
		else if (!ft_strcmp(s_line[0], "SO"))
			cub3d->map->textures->so++;
		else if (!ft_strcmp(s_line[0], "WE"))
			cub3d->map->textures->we++;
		else if (!ft_strcmp(s_line[0], "EA"))
			cub3d->map->textures->ea++;
		else if (!ft_strcmp(s_line[0], "F"))
			cub3d->map->textures->f++;
		else if (!ft_strcmp(s_line[0], "C"))
			cub3d->map->textures->c++;
		free_splits(s_line);
	}
}

static int	check_number_args_config(char **data_file, t_cub3d *cub3D,
						int i, int error)
{
	char	**s_line;
	char	*trimmed;

	while (data_file[++i])
	{
		trimmed = trim_spaces_around_commas(data_file[i]);
		s_line = ft_split(trimmed, ' ');
		if (count_words(trimmed) != 2 && (!ft_strcmp(s_line[0], "NO")
				|| !ft_strcmp(s_line[0], "SO") || !ft_strcmp(s_line[0], "WE")
				|| !ft_strcmp(s_line[0], "EA") || !ft_strcmp(s_line[0], "F")
				|| !ft_strcmp(s_line[0], "C")))
			error = 1;
		free(trimmed);
		check_rgb_config(data_file, s_line, cub3D);
		free_splits(s_line);
	}
	if (error == 1)
		return (1);
	return (0);
}

static void	check_if_configs_above(char **data_file, t_cub3d *cub3D)
{
	int		i;
	int		flag;
	char	**s_line;

	i = -1;
	flag = 0;
	while (data_file[++i])
	{
		s_line = ft_split(data_file[i], ' ');
		if (!ft_strcmp(s_line[0], "NO") || !ft_strcmp(s_line[0], "SO")
			|| !ft_strcmp(s_line[0], "WE") || !ft_strcmp(s_line[0], "EA")
			|| !ft_strcmp(s_line[0], "F") || !ft_strcmp(s_line[0], "C"))
			flag++;
		else
		{
			if (flag != 6 && ft_strcmp(s_line[0], "\n"))
			{
				free_splits(s_line);
				free_splits(data_file);
				p_error(CONFIGS, cub3D);
			}
		}
		free_splits(s_line);
	}
}

static void	check_rgb_config(char **data_file, char **s_line, t_cub3d *cub3D)
{
	int		i;
	int		value;
	int		flag;
	int		v_flag;
	char	**s_rgb;

	i = -1;
	flag = 0;
	v_flag = 0;
	if (!ft_strcmp(s_line[0], "F") || !ft_strcmp(s_line[0], "C"))
	{
		s_rgb = ft_split(s_line[1], ',');
		check_rgb_character(data_file, s_line, cub3D, s_rgb);
		while (s_rgb[++i])
		{
			value = ft_atoi(s_rgb[i]);
			if (value > 255 || value < 0)
				v_flag = 1;
			if (s_rgb[i] && ft_strcmp(s_rgb[i], "\n"))
				flag++;
		}
		free_splits(s_rgb);
		if (flag != 3 || v_flag == 1)
			free_arrays(data_file, s_line, cub3D);
	}
}

char	*trim_spaces_around_commas(char *str)
{
	size_t	len;
	size_t	i;
	int		j;
	char	*ret;

	i = -1;
	j = 0;
	len = ft_strlen(str);
	ret = ft_calloc(sizeof(char), len + 1);
	while (++i < len)
	{
		if (str[i] == ',')
		{
			while (j > 0 && (ret[j - 1] == ' ' || ret[j - 1] == '\t'))
				j--;
			ret[j++] = ',';
			while (i + 1 < len && (str[i + 1] == ' ' || str[i + 1] == '\t'))
				i++;
		}
		else
			ret[j++] = str[i];
	}
	ret[j] = '\0';
	return (ret);
}
