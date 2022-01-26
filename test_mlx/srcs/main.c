#include "../includes/test_mlx.h"

void	set_default_obj(t_main *obj)
{
	obj->min = init_complex(-2.0, -2.0);
	if (HEIGHT > WIDTH)
	{
		obj->max.re = 2.0;
		obj->max.im = obj->min.im + (obj->max.re - obj->min.re) * HEIGHT / WIDTH;
	}
	else
	{
		obj->max.im = 2.0;
		obj->max.re = obj->min.re + (obj->max.im - obj->min.im) * WIDTH / HEIGHT;
	}
	obj->color_shift = 0;
	obj->bright_shift = 0;
}

static void	init_obj(t_main *obj)
{
	obj->mlx = mlx_init();
	if (!obj->mlx)
		exit (1);
	obj->window = mlx_new_window(obj->mlx, WIDTH, HEIGHT, "Object");
	if (!obj->window)
		exit (2);
	obj->image.image = mlx_new_image(obj->mlx, WIDTH, HEIGHT);
	if (!obj->image.image)
		exit (3);
	obj->image.address = mlx_get_data_addr(obj->image.image,
	&obj->image.bit_per_pixel, &obj->image.line_length, &obj->image.endian);
	set_default_obj(obj);
	// obj->formula_fractol = get_obj();
	// mlx_hook(fractol->window, 2, 1L << 0, press_key, fractol);
}

int	main(void)
{
	t_main	obj;

	init_obj(&obj);
	draw_obj(&obj);
	mlx_mouse_hook(obj.window, zoom, &obj);
	mlx_hook(obj.window, 2, 1L << 0, move_image, &obj);
	mlx_loop(obj.mlx);
	return (0);
}
