#include "../includes/fractol.h"

static int	check_name_fractal(char *name_fractol)
{
	if (!ft_strcmp(name_fractol, "Mandelbrot") || \
	!ft_strcmp(name_fractol, "Julia") || \
	!ft_strcmp(name_fractol, "Mandelbar") || \
	!ft_strcmp(name_fractol, "Celtic Perpendicular") || \
	!ft_strcmp(name_fractol, "Celtic Mandelbar"))
		return (1);
	else
		return (0);
}

static int	check_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str && str[i] == '-' && str[i + 1])
		i++;
	if (str && (str[i] == '.' || \
	(str[i] == '0' && str[i + 1] && str[i + 1] != '.')))
		return (0);
	while (str && str[i] != '.' && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[i] == '.' && str[i + 1])
		i++;
	else if (str[i] == '.' && !str[i + 1])
		return (0);
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validation_input_data(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
		return (check_name_fractal(argv[1]));
	else if (argc == 3 && !ft_strcmp(argv[1], "Julia") && \
	check_valid_num(argv[2]))
		return (1);
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia") && \
	check_valid_num(argv[2]) && check_valid_num(argv[3]))
		return (1);
	return (0);
}
