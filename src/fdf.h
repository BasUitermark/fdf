#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include "../include/mlx/mlx.h"
# include "../include/libft/include/libft.h"
# include <stdio.h> //DELETE THIS
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_init
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}	t_init;

typedef struct s_coord
{
	int	width;
	int	depth;
	int	height;
}	t_coord;

typedef struct s_map
{
	int	*map_points;
	int	map_width;
	int	map_depth;
}	t_map;

void	ft_draw_line(t_init *init, t_coord start, t_coord end);
t_map	parse_map(char *filepath);
void	error(char *error_msg);

#endif
