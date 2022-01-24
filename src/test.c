#include "../include/fdf.h"
#include <stdio.h>
#include <math.h>

void	line_val(t_coord line)
{
	double	m;
	double	c;
	double	x;
	double	y;

	m = (line.y2 - line.y1) / (line.x2 - line.x1); //y increment per 1 increment of x
	c = line.y1 - m * line.x1;
	printf ("%lf\n", c);
	x = line.x1;
	while (x < line.x2)
	{
		y = m * x + c;
		y = round(y);
		printf ("x = %lf\ny = %lf\n", x, y);
		x++;
	}
}

int	main(int argc, char const *argv[])
{
	t_coord	line;

	line.x1 = 10;
	line.y1 = 10;
	line.x2 = 19;
	line.y2 = 13;
	line_val(line);
}
