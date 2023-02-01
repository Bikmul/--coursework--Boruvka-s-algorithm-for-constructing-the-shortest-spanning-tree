#pragma once

# include "get_next_line/get_next_line.h"
# include "stdio.h"
# include "minilibx/mlx.h"
# include <string.h>

# define PIXEL 64

typedef struct s_coord
{
	int	x;
	int	y;	
}				t_coord;

typedef struct s_image
{
	void	*image_wall;
	void	*image_floor;
}		t_image;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	char				**arr;
	int					length;
	int					count;
	int					fd;
	int					flag_dir;
	t_image				image;
	void				*tmp_image;
	char				*c;
}				t_vars;

void	error(int n);
void	fill(t_vars *vars, char *argv);
void	memory(t_vars *vars);
int		map(t_vars *vars, char *argv);
void	map_check(t_vars *vars, int *flag_n, char *line);
int		map_check2(t_vars *vars, char *line, int flag_n);
int		check_symbols(char *line);
void	init(t_vars *vars);
void	image(t_vars *vars, int h, int w);
int		draw_map(t_vars *vars);
void	draw_images(t_vars *vars, char c, int i, int j);
void	draw_images_e_c_v(t_vars *vars, char c, int i, int j);
int		close_window(t_vars *vars);