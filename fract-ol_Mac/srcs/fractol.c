#include "../includes/fractol.h"

unsigned int	(*get_fractol(char *name_fractol))(t_fractol *fractol)
{
	if (!ft_strcmp(name_fractol, "Mandelbrot"))
		return (&init_mandelbrot);
	else
		return (0);
}

void	set_default_fractol(t_fractol *fractol)
{
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max_iteration = 50;
	if (HEIGHT > WIDTH)
	{
		fractol->max.re = 2.0;
		fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	}
	else
	{
		fractol->max.im = 2.0;
		fractol->max.re = fractol->min.re + (fractol->max.im - fractol->min.im) * WIDTH / HEIGHT;
	}
	fractol->color_shift = 0;
	fractol->bright_shift = 0;
}

static void	init_fractol(t_fractol *fractol, char *name_fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit (1);
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, name_fractol);
	if (!fractol->window)
		exit (2);
	fractol->image.image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image.image)
		exit (3);
	fractol->image.address = mlx_get_data_addr(fractol->image.image,
	&fractol->image.bit_per_pixel, &fractol->image.line_length, &fractol->image.endian);
	set_default_fractol(fractol);
	fractol->formula_fractol = get_fractol(name_fractol);
	mlx_hook(fractol->window, 2, 1L << 0, press_key, fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 2 && get_fractol(argv[1]))
	{
		init_fractol(&fractol, argv[1]);
		draw_fractol(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		ft_putstr_fd("print data\n", 2);
	return (0);
}
