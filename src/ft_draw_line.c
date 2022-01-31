#include "../include/fdf.h"

void	ft_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical(t_coord line, t_init *init)
{
	double	x;
	double	y;

	x = line.x1;
	if (line.y2 - line.y1 > 0)
	{
		printf("Vertical\n");
		y = line.y1;
		while (y < line.y2)
		{
			printf("X: %lf\nY: %lf\n", x, y);
			// ft_pixelput(&init->img, x, y, 0xFF0000);
			y++;
		}
	}
	else
	{
		printf("Vertical invert\n");
		y = line.y2;
		while (y < line.y1)
		{
			printf("X: %lf\nY: %lf\n", x, y);
			// ft_pixelput(&init->img, x, y, 0xFF0000);
			y++;
		}
	}
}

void	draw_horizontal(t_coord line, t_init *init)
{
	double	x;
	double	y;

	y = line.y1;
	if (line.x2 - line.x1 > 0)
	{
		printf("Horizontal\n");
		x = line.x1;
		while (x < line.x2)
		{
			printf("X: %lf\nY: %lf\n", x, y);
			// ft_pixelput(&init->img, x, y, 0xFF0000);
			x++;
		}
	}
	else
	{
		printf("Horizontal invert\n");
		x = line.x2;
		while (x < line.x1)
		{
			printf("X: %lf\nY: %lf\n", x, y);
			// ft_pixelput(&init->img, x, y, 0xFF0000);
			x++;
		}
	}
}

void	draw_diagonal(t_coord line, t_init *init)
{
	double	m;
	double	c;
	double	x;
	double	y;

	m = (line.y2 - line.y1) / (line.x2 - line.x1);
	c = line.y1 - (m * line.x1);
	x = line.x1;
	printf("Horizontal invert\n");
	while (x < line.x2)
	{
		y = m * x + c;
		y = round(y);
		printf("X: %lf\nY: %lf\n", x, y);
		// ft_pixelput(&init->img, x, y, 0xFF0000);
		x++;
	}
}

void	draw_line(t_coord line, t_init *init)
{
	double	m;
	double	c;
	double	x;
	double	y;

	if (line.x2 - line.x1 == 0 && line.y2 - line.y1 == 0)
		return ;
	else if (line.x2 - line.x1 == 0)
		draw_vertical(line, &init);
	else if (line.y2 - line.y1 == 0)
		draw_horizontal(line, &init);
	else
		draw_diagonal(line, &init);

}

int	main(int argc, char const *argv[])
{
	t_init	init;
	t_coord	line;

	line.x1 = 100;
	line.y1 = 100;
	line.x2 = 100;
	line.y2 = 550;
	init.mlx = mlx_init();
	init.mlx_win = mlx_new_window(init.mlx, WIDTH, HEIGHT, "TEST");
	init.img.img = mlx_new_image(init.mlx, WIDTH, HEIGHT);
	// init.img.addr = mlx_get_data_addr(init.img.img, &init.img.bits_per_pixel, \
	// 			&init.img.line_length, &init.img.endian);
	draw_line(line, &init);
	// mlx_loop(init.mlx);
}
