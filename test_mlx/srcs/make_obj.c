#include "../includes/test_mlx.h"

unsigned int	make_obj(t_main *obj)
{
	int			color;
	t_complex	z;

	color = 0;
	z = init_complex(obj->vector.re, obj->vector.im);
	if (pow(z.re, 2) + pow(z.im, 2) <= 4)
		color = 100;
	return (color);
}
