/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:36:10 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/15 12:35:54 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_colored_char(char c);

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if ((!*s1) && (!*s2))
		return (0);
	if (*s1 > *s2)
		return (*s1 - *s2);
	else if (*s1 < *s2)
		return (*s1 - *s2);
	return (0);
}

static void	print_colored_char(char c)
{
	if (c == '0')
		ft_printf("\033[47m \033[0m");
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ft_printf("\033[42m \033[0m");
	else
		ft_printf("\033[41m \033[0m");
}

void	print_colored_matrix(char *matrix[])
{
	int		i;
	char	*p;

	i = 0;
	while (matrix[i])
	{
		p = matrix[i];
		while (*p != '\0')
		{
			print_colored_char(*p);
			p++;
		}
		ft_printf("\n");
		i++;
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
