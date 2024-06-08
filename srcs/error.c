
# include "cub3d.h"

void	p_error(t_error type)
{
	if (type == N_ARGS)
		ft_printf("Invalid number of arguments.\n");
	else if (type == MAP_NAME)
		ft_printf("Invalid file name.\n");
	else if (type == OPEN_ERROR)
		ft_printf("Error trying to open the file.\n");
	else if (type == NOT_ABOVE)
		ft_printf("Configs are not first parameters.\n");
	else if (type == CONFIGS)
		ft_printf("Missing/Wrong configuration in the file.\n");
	exit (EXIT_FAILURE);
}