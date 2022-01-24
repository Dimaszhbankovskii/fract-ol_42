#include "../includes/fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->address + (y * image->line_length + x * (image->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}
