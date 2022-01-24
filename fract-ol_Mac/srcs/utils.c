#include "../includes/fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}
