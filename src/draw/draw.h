#ifndef DRAW_H
# define DRAW_H
# include "../fdf.h"

void	ft_pixelput(t_data *data, t_coord coord, int color);
void	ft_draw_line(t_init *init, t_coord s, t_coord e);

#endif