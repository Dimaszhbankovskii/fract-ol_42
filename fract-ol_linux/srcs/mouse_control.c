#include "../includes/fractol.h"

static double	change_border(double point, double border, double k_zoom)
{
	return (point - (point - border) / k_zoom);
}

int	zoom(int keycode, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	t_complex	window;
	double		k_zoom;

	k_zoom = 1;
	window = init_complex(fractol->max.re - fractol->min.re, \
	fractol->max.im - fractol->min.im);
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		mouse = init_complex(\
		fractol->min.re + (double)x * window.re / WIDTH, \
		fractol->max.im - (double)y * window.im / HEIGHT);
		if (keycode == MOUSE_SCROLL_UP)
			k_zoom = ZOOM_IN;
		else if (keycode == MOUSE_SCROLL_DOWN)
			k_zoom = ZOOM_OUT;
		fractol->min.re = change_border(mouse.re, fractol->min.re, k_zoom);
		fractol->min.im = change_border(mouse.im, fractol->min.im, k_zoom);
		fractol->max.re = change_border(mouse.re, fractol->max.re, k_zoom);
		fractol->max.im = change_border(mouse.im, fractol->max.im, k_zoom);
		draw_fractol(fractol);
	}
	return (0);
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	fractol->k_julia = init_complex(4 * ((double)x / (double)WIDTH - 0.5), \
	4 * ((double)(HEIGHT - y) / (double)HEIGHT - 0.5));
	draw_fractol(fractol);
	return (0);
}
