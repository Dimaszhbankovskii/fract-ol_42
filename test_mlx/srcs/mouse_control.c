#include "../includes/test_mlx.h"

static double	interpolate(double point, double border, double k_zoom)
{
	return (point - (point - border) / k_zoom);
}

int	zoom(int keycode, int x, int y, t_main *obj)
{
	t_complex	mouse;
	double		k_zoom;

	k_zoom = 1;
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		mouse = init_complex(obj->min.re + (double)x / (WIDTH / (obj->max.re - obj->min.re)), 
		obj->max.im - (double)y / (HEIGHT / (obj->max.im - obj->min.im)));
		if (keycode == MOUSE_SCROLL_UP)
			k_zoom = 1.1;
		else if (keycode == MOUSE_SCROLL_DOWN)
			k_zoom = 0.9;
		obj->min.re = interpolate(mouse.re, obj->min.re, k_zoom);
		obj->min.im = interpolate(mouse.im, obj->min.im, k_zoom);
		obj->max.re = interpolate(mouse.re, obj->max.re, k_zoom);
		obj->max.im = interpolate(mouse.im, obj->max.im, k_zoom);
		draw_obj(obj);
	}
	return (0);
}
