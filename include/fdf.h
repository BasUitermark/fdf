#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include "libft/include/libft.h"
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
	double	x1;
	double	x2;
	double	y1;
	double	y2;
}	t_coord;

char	*ft_parse(char *filepath);

#endif
