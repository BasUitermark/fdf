#include "../include/minilibx_mms_20191025_beta/mlx.h"
#include "../include/fdf.h"
#include <stdio.h>

/*
	
*/

void	ft_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	line_val(t_coord line, t_init *init)
{
	double	m;
	double	c;
	double	x;
	double	y;

	m = (line.y2 - line.y1) / (line.x2 - line.x1);
	c = line.y1 - m * line.x1;
	x = line.x1;
	while (x < line.x2)
	{
		y = m * x + c;
		y = round(y);
		ft_pixelput(&init->img, x, y, 0xFFFFFF);
		x++;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img.img, 0, 0);
}

int	main(int argc, char const *argv[])
{
	t_init	init;
	t_coord	line;

	line.x1 = 100;
	line.y1 = 100;
	line.x2 = 200;
	line.y2 = 550;
	init.mlx = mlx_init();
	init.mlx_win = mlx_new_window(init.mlx, WIDTH, HEIGHT, "TEST");
	init.img.img = mlx_new_image(init.mlx, WIDTH, HEIGHT);
	init.img.addr = mlx_get_data_addr(init.img.img, &init.img.bits_per_pixel, \
				&init.img.line_length, &init.img.endian);
	line_val(line, &init);
	mlx_loop(init.mlx);
	return (0);
}
