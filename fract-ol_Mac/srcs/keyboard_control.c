#include "../includes/fractol.h"

int	press_key(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_R)
	{
		set_default_fractol(fractol);
		draw_fractol(fractol);
	}
	return (0);
}
