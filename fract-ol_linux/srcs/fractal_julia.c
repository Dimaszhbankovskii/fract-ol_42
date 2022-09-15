#include "../includes/fractol.h"

unsigned int	init_julia(t_fractol *fractol)
{
	unsigned int	iteration;
	t_complex		z;

	iteration = 0;
	z = init_complex(fractol->vector.re, fractol->vector.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && \
	iteration < fractol->max_iteration)
	{
		z = init_complex(pow(z.re, 2) - pow(z.im, 2) + fractol->k_julia.re, \
		2.0 * z.re * z.im + fractol->k_julia.im);
		iteration++;
	}
	return (iteration);
}
