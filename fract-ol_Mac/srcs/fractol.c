#include "../includes/fractol.h"

unsigned int	(*get_formula_fractol(char *name_fractol))(t_fractol *fractol)
{
	if (!ft_strcmp(name_fractol, "Mandelbrot"))
		return (&init_mandelbrot);
	else if (!ft_strcmp(name_fractol, "Julia"))
		return (&init_julia);
	else if (!ft_strcmp(name_fractol, "Mandelbar"))
		return (&init_mandelbar);
	else if (!ft_strcmp(name_fractol, "Celtic Perpendicular"))
		return (&init_celtic_perpendicular);
	else if (!ft_strcmp(name_fractol, "Celtic Mandelbar"))
		return (&init_celtic_mandelbar);
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
		fractol->max.im = fractol->min.im + \
		(fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	}
	else
	{
		fractol->max.im = 2.0;
		fractol->max.re = fractol->min.re + \
		(fractol->max.im - fractol->min.im) * WIDTH / HEIGHT;
	}
	if (fractol->argc == 1)
		fractol->k_julia = init_complex(-0.6, 0.5);
	else if (fractol->argc == 2)
		fractol->k_julia = init_complex(ft_atof(fractol->argv[1]), 0.5);
	else if (fractol->argc == 3)
		fractol->k_julia = init_complex(ft_atof(fractol->argv[1]), \
		ft_atof(fractol->argv[2]));
	fractol->color_shift = 0;
}

static void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit(error_mess("Error: connection MLX\n", fractol, 3));
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, \
	fractol->argv[0]);
	if (!fractol->window)
		exit(error_mess("Error: create MLX Window\n", fractol, 3));
	fractol->image.image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image.image)
		exit(error_mess("Error: create MLX Image\n", fractol, 4));
	fractol->image.address = mlx_get_data_addr(fractol->image.image, \
	&fractol->image.bit_per_pixel, &fractol->image.line_length, \
	&fractol->image.endian);
	set_default_fractol(fractol);
	fractol->formula_fractol = get_formula_fractol(fractol->argv[0]);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = malloc_fractol();
	if (validation_input_data(argc, argv))
	{
		parsing_input_data(argc, argv, fractol);
		init_fractol(fractol);
		draw_fractol(fractol);
		mlx_mouse_hook(fractol->window, zoom, fractol);
		mlx_hook(fractol->window, 2, 1L << 0, press_key, fractol);
		if (!ft_strcmp(argv[1], "Julia"))
			mlx_hook(fractol->window, 6, 1L << 6, julia_motion, fractol);
		mlx_loop(fractol->mlx);
	}
	else
	{
		free_fractol(fractol);
		print_help_mess();
	}	
	return (0);
}
