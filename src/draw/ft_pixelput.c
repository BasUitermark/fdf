#include "draw.h"

void	ft_pixelput(t_data *data, t_coord coord, int color)
{
	char	*dst;

	dst = data->addr + (coord.y * data->line_length + coord.x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
