#include "../includes/fractol.h"

static void	move_image(int keycode, t_fractol *fractol)
{
	t_complex	window;

	window = init_complex(fabs(fractol->max.re - fractol->min.re), \
	fabs(fractol->max.im - fractol->min.im));
	if (keycode == MOVE_UP)
	{
		fractol->max.im += window.im * MOVE_STEP;
		fractol->min.im += window.im * MOVE_STEP;
	}
	else if (keycode == MOVE_DOWN)
	{
		fractol->max.im -= window.im * MOVE_STEP;
		fractol->min.im -= window.im * MOVE_STEP;
	}
	else if (keycode == MOVE_LEFT)
	{
		fractol->max.re -= window.re * MOVE_STEP;
		fractol->min.re -= window.re * MOVE_STEP;
	}
	else if (keycode == MOVE_RIGHT)
	{
		fractol->max.re += window.re * MOVE_STEP;
		fractol->min.re += window.re * MOVE_STEP;
	}
	draw_fractol(fractol);
}

static void	change_color(int keycode, t_fractol *fractol)
{
	if (keycode == COLOR_SHIFT_RIGHT)
	{
		fractol->color_shift += (unsigned char)(fractol->max_iteration / 10);
		if ((unsigned int)fractol->color_shift > fractol->max_iteration)
			fractol->color_shift = 0;
	}
	else if (keycode == COLOR_SHIFT_LEFT)
	{
		fractol->color_shift -= (unsigned char)(fractol->max_iteration / 10);
		if ((unsigned int)fractol->color_shift > fractol->max_iteration)
			fractol->color_shift = (unsigned char)fractol->max_iteration;
	}
	draw_fractol(fractol);
}

static void	change_max_iteration(int keycode, t_fractol *fractol)
{
	if (keycode == MAX_ITERATION_UP)
	{
		if (fractol->max_iteration > 50)
			fractol->max_iteration += 5;
		else
			fractol->max_iteration++;
	}
	else if (keycode == MAX_ITERATION_DOWN)
	{
		if (fractol->max_iteration > 55)
			fractol->max_iteration -= 5;
		else
			fractol->max_iteration--;
	}
	draw_fractol(fractol);
}

int	press_key(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
	{
		free_fractol(fractol);
		exit (0);
	}
	else if (keycode == MOVE_UP || keycode == MOVE_DOWN || \
	keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		move_image(keycode, fractol);
	else if (keycode == MAX_ITERATION_UP || keycode == MAX_ITERATION_DOWN)
		change_max_iteration(keycode, fractol);
	else if (keycode == COLOR_SHIFT_RIGHT || keycode == COLOR_SHIFT_LEFT)
		change_color(keycode, fractol);
	else if (keycode == DEFAULT_FRACTOL)
	{
		set_default_fractol(fractol);
		draw_fractol(fractol);
	}
	return (0);
}
