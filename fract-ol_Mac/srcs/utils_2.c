#include "../includes/fractol.h"

int	end_program(t_fractol *fractol)
{
	free_fractol(fractol);
	return (0);
}

static int	ft_atoi_ll(const char *str)
{
	int				i;
	long long int	num;
	int				sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

double	ft_atof(const char *str)
{
	double	d1;
	double	d2;
	char	*c;
	int		len;

	c = (char *)str;
	d1 = (double)ft_atoi_ll(c);
	while (c && *c != '.' && *c)
		c++;
	if (c && *c == '.')
		c++;
	d2 = (double)ft_atoi_ll(c);
	len = ft_strlen(c);
	while (len--)
		d2 /= 10;
	if (d1 >= 0 && str[0] != '-')
		return (d1 + d2);
	else
		return (d1 - d2);
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
