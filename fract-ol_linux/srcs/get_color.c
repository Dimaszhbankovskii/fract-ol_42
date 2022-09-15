#include "../includes/fractol.h"

int	get_color(unsigned int iteration, t_fractol *fractol)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iteration + fractol->color_shift < fractol->max_iteration)
		t = (double)(iteration + fractol->color_shift) \
		/ (double)fractol->max_iteration;
	else
		t = (double)iteration / (double)fractol->max_iteration;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (red << 16 | green << 8 | blue);
}
