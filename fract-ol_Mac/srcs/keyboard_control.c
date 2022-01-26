#include "../includes/fractol.h"

static void	move_image(int keycode, t_fractol *fractol)
{
	if (keycode == MOVE_UP)
	{
		fractol->max.im += fabs(fractol->max.im - fractol->min.im) * STEP_MOVE;
		fractol->min.im += fabs(fractol->max.im - fractol->min.im) * STEP_MOVE;
	}
	else if (keycode == MOVE_DOWN)
	{
		fractol->max.im -= fabs(fractol->max.im - fractol->min.im) * STEP_MOVE;
		fractol->min.im -= fabs(fractol->max.im - fractol->min.im) * STEP_MOVE;
	}
	else if (keycode == MOVE_LEFT)
	{
		fractol->max.re -= fabs(fractol->max.re - fractol->min.re) * STEP_MOVE;
		fractol->min.re -= fabs(fractol->max.re - fractol->min.re) * STEP_MOVE;
	}
	else if (keycode == MOVE_RIGHT)
	{
		fractol->max.re += fabs(fractol->max.re - fractol->min.re) * STEP_MOVE;
		fractol->min.re += fabs(fractol->max.re - fractol->min.re) * STEP_MOVE;
	}
	draw_fractol(fractol);
}

static void	change_bright(int keycode, t_fractol *fractol)
{
	if (keycode == BRIGHT_UP && fractol->color_shift < 255)
		fractol->color_shift++;
	else if (keycode == BRIGHT_DOWN && fractol->color_shift > 0)
		fractol->color_shift--;
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
	else if (keycode == BRIGHT_UP || keycode == BRIGHT_DOWN)
		change_bright(keycode, fractol);
	else if (keycode == DEFAULT_FRACTOL)
	{
		set_default_fractol(fractol);
		draw_fractol(fractol);
	}
	return (0);
}
