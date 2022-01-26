#include "../includes/test_mlx.h"

int	get_color(unsigned int iteration, t_fractol *fractol)
{
	int	color;
	int	t;
	int	red;
	int	green;
	int	blue;

	if (iteration == fractol->max_iteration)
		return (0);
	color = 0;
	t = (double)iteration / (double)fractol->max_iteration;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	color += red;
	color <<= 8;
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color += green;
	color <<= 8;
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
