#include "../includes/fractol.h"

t_fractol	*malloc_fractol(void)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		exit(error_mess("Error: malloc 'fractol'\n", NULL, 1));
	fractol->mlx = NULL;
	fractol->window = NULL;
	fractol->image.image = NULL;
	fractol->image.address = NULL;
	return (fractol);
}

void	free_fractol(t_fractol *fractol)
{
	if (fractol)
	{
		if (fractol->image.image)
			mlx_destroy_image(fractol->mlx, fractol->image.image);
		if (fractol->window)
			mlx_destroy_window(fractol->mlx, fractol->window);
		if (fractol->mlx)
			free (fractol->mlx);
		fractol->mlx = NULL;
		free (fractol);
		fractol = NULL;
	}
}

int	error_mess(char *mess, t_fractol *fractol, int code_error)
{
	ft_putstr_fd(mess, 2);
	free_fractol(fractol);
	return (code_error);
}

t_complex	init_complex(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->address + (y * image->line_length + \
	x * (image->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}
