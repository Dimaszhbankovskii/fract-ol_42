#include "../includes/fractol.h"

void	draw_fractol(t_fractol *fractol)
{
	int				y;
	int				x;
	unsigned int	iteration;
	int				color;

	fractol->unit_vector = init_complex((fractol->max.re - fractol->min.re) / WIDTH,
	(fractol->max.im - fractol->min.im) / HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractol->vector = init_complex(fractol->min.re + x * fractol->unit_vector.re,
			fractol->max.im - y * fractol->unit_vector.im);
			iteration = init_mandelbrot(fractol);
			color = get_color(iteration, fractol);
			my_mlx_pixel_put(&fractol->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image.image, 0, 0);
}
