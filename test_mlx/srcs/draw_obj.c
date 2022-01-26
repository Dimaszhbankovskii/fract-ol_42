#include "../includes/test_mlx.h"

void	draw_obj(t_main *obj)
{
	int				y;
	int				x;
	// unsigned int	iteration;
	int				color;

	obj->unit_vector = init_complex((obj->max.re - obj->min.re) / WIDTH,
	(obj->max.im - obj->min.im) / HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			obj->vector = init_complex(obj->min.re + x * obj->unit_vector.re,
			obj->max.im - y * obj->unit_vector.im);
			color = make_obj(obj);
			// color = get_color(iteration, fractol);
			my_mlx_pixel_put(&obj->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(obj->mlx, obj->window, obj->image.image, 0, 0);
}
