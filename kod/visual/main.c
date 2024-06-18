#include "so_long.h"

void	error(int n)
{
	if (n == 1)
		printf("Error: wrong number of arguments\n");
	else if (n == 2)
		printf("Error: file read error\n");
	else if (n == 3)
		printf("Map error: invalid string length\n");
	else if (n == 5)
		printf("Map error: invalid symbols in the map\n");
	else if (n == 6)
		printf("Map error: empty lines in file\n");
	exit(1);
}

void	init(t_vars *vars)
{
	vars->flag_dir = 0;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->arr = NULL;
	vars->c = "1";
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	exit (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		error (1);
		exit (1);
	}
	init(&vars);
	map(&vars, argv[1]);
	memory(&vars);
	fill(&vars, argv[1]);
	vars.mlx = mlx_init();
	image(&vars, 0, 0);
	vars.win = mlx_new_window(vars.mlx, PIXEL * vars.length,
			PIXEL * vars.count, "Matrix");
	mlx_hook(vars.win, 17, 1L << 5, close_window, &vars);
	mlx_loop_hook(vars.mlx, draw_map, &vars);
	mlx_loop(vars.mlx);
	return (0);
}