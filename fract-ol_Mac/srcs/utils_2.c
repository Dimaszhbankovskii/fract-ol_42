#include "../includes/fractol.h"

int	end_program(t_fractol *fractol)
{
	free_fractol(fractol);
	return (0);
}

void	print_help_mess(void)
{
	ft_putstr_fd("-------------------------------------------------\n", 1);
	ft_putstr_fd("--------------- Help information ----------------\n", 1);
	ft_putstr_fd("-------------------------------------------------\n", 1);
	ft_putstr_fd("Enter name of the fractal from the proposed list:\n", 1);
	ft_putstr_fd("\n  1. Mandelbrot\n", 1);
	ft_putstr_fd("\n  2. Julia\n", 1);
	ft_putstr_fd("\n  3. Mandelbar\n", 1);
	ft_putstr_fd("\n  4. 'Celtic Perpendicular'\n", 1);
	ft_putstr_fd("\n  5. 'Celtic Mandelbar'\n", 1);
	ft_putstr_fd("-------------------------------------------------\n", 1);
	ft_putstr_fd("-------------------------------------------------\n", 1);
}
