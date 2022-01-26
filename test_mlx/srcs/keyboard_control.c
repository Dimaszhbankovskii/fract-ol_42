#include "../includes/test_mlx.h"

int	move_image(int keycode, t_main *obj)
{
	double	k_move;
	double	width;
	double	height;

	k_move = 0.025;
	width = obj->max.re - obj->min.re;
	height = obj->max.im - obj->min.im;
	if (keycode == KEY_UP)
	{
		obj->max.im = obj->max.im + width * k_move;
		obj->min.im = obj->min.im + width * k_move;
	}
	else if (keycode == KEY_DOWN)
	{
		obj->max.im = obj->max.im - width * k_move;
		obj->min.im = obj->min.im - width * k_move;
	}
	else if (keycode == KEY_LEFT)
	{
		obj->max.re = obj->max.re - width * k_move;
		obj->min.re = obj->min.re - width * k_move;
	}
	else if (keycode == KEY_RIGHT)
	{
		obj->max.re = obj->max.re + width * k_move;
		obj->min.re = obj->min.re + width * k_move;
	}
	draw_obj(obj);
	return (0);
}

int	press_key(int keycode, t_main *obj)
{
	(void) obj;
	if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_LEFT)
		ft_putstr_fd("LEFT\n", 1);
	else if (keycode == KEY_RIGHT)
		ft_putstr_fd("RIGHT\n", 1);
	else if (keycode == KEY_UP)
		ft_putstr_fd("UP\n", 1);
	else if (keycode == KEY_DOWN)
		ft_putstr_fd("DOWN\n", 1);
	else
	{
		if (keycode != 256)
		{
			ft_putnbr_fd(keycode, 1);
			ft_putstr_fd("\n", 1);
		}
	}
	return (0);
}
