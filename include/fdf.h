#ifndef FDF_H
# define FDF_H
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
}	t_init;

typedef struct s_coord
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
}	t_coord;

#endif
