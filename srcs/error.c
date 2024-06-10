
# include "cub3d.h"

void	p_error(t_error type)
{
	if (type == N_ARGS)
		ft_printf("Error\nInvalid number of arguments.\n");
	else if (type == MAP_NAME)
		ft_printf("Error\nInvalid file name.\n");
	else if (type == OPEN_ERROR)
		ft_printf("Error\nError trying to open the file.\n");
	else if (type == CONFIGS)
		ft_printf("Error\nMissing/Wrong configuration in the file.\n");
	else if (type == MEMORY)
		ft_printf("Error\nBad Alloc Error\n");
	exit (EXIT_FAILURE);
}