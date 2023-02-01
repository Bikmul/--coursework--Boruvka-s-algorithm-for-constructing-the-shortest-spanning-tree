#include "so_long.h"

void	image(t_vars *vars, int h, int w)
{
	vars->image.image_wall
		= mlx_xpm_file_to_image(vars->mlx, "./images/1.xpm", &h, &w);
	vars->image.image_floor
		= mlx_xpm_file_to_image(vars->mlx, "./images/0.xpm", &h, &w);
}

void	draw_images(t_vars *vars, char c, int i, int j)
{
	if (c == '0')
	{
		vars->tmp_image = vars->image.image_floor;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
	if (c == '1')
	{		
		vars->tmp_image = vars->image.image_wall;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
	else if ( c != '0')
		draw_images_e_c_v(vars, c, i, j);
}

int	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->count)
	{
		j = -1;
		while (++j < vars->length)
			draw_images(vars, vars->arr[i][j], i, j);
	}
	return (0);
}

void	draw_images_e_c_v(t_vars *vars, char c, int i, int j)
{
	if(c != '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
}