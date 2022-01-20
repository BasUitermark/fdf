#include "../include/minilibx_mms_20191025_beta/mlx.h"
#include "../include/fdf.h"
#include <stdio.h>

void	ft_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data data, t_coord coord, t_init *init)
{
	if (coord.x_start - coord.x_end != 0)
	{
		while (coord.x_start < coord.x_end)
		{
			ft_pixelput(&data, coord.x_start, coord.y_start, 0xFFFFFF);
			coord.x_start++;
		}
	}
	else if (coord.y_start - coord.y_end != 0)
	{
		while (coord.y_start < coord.y_end)
		{
			ft_pixelput(&data, coord.x_start, coord.y_start, 0xFFFFFF);
			coord.y_start++;
		}
	}
	else
		return ;
	mlx_put_image_to_window(init->mlx, init->mlx_win, data.img, 0, 0);
}

void	draw_square(t_data data, int x_len, int y_len, int *corner, t_init init)
{
	t_coord	coord;

	coord.x_start = corner[0];
	coord.x_end = corner[0] + x_len;
	coord.y_start = corner[1];
	coord.y_end = corner[1] + y_len;
	draw_line(data, coord, &init);
}

int	main(int argc, char const *argv[])
{
	t_init	init;
	t_data	img;
	int		corner[2];

	corner[0] = 20;
	corner[1] = 20;
	init.mlx = mlx_init();
	init.mlx_win = mlx_new_window(init.mlx, WIDTH, HEIGHT, "TEST");
	img.img = mlx_new_image(init.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
				&img.line_length, &img.endian);
	draw_square(img, 100, 100, corner, init);
	mlx_loop(init.mlx);
	return (0);
}
