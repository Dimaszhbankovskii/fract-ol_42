#include "../includes/fractol.h"

typedef struct s_var
{
	void	*mlx;
	void	*window;
}				t_var;


void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->address + (y * image->line_length + x * (image->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(int x1, int x2, int y1, int y2, t_image *image, int color)
{
	int	width;
	int	height;

	height = y1;
	while (height <= y2)
	{
		width = x1;
		while (width <= x2)
		{
			my_mlx_pixel_put(image, width, height, color);
			width++;
		}
		height++;
	}
}

int	close_window(int keycode, t_var *vars)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->window);
	else
	{
		ft_putnbr_fd(keycode, 1);
		ft_putstr_fd("\n", 1);
	}
	return (0);
}

int	mouse_hook(int keycode, t_var *vars)
{
	(void) vars;
	if (keycode == 1)
		ft_putstr_fd("lk\n", 1);
	else if (keycode == 2)
		ft_putstr_fd("rk\n", 1);
	else if (keycode == 3)
		ft_putstr_fd("mk\n", 1);
	else if (keycode == 4)
		ft_putstr_fd("scu\n", 1);
	else if (keycode == 5)
		ft_putstr_fd("scd\n", 1);
	return (0);
}

int	main(void)
{
	t_var	vars;
	t_image	image;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 800, 400, "Fractol");
	image.image = mlx_new_image(vars.mlx, 800, 400);
	image.address = mlx_get_data_addr(image.image, &image.bit_per_pixel, &image.line_length, &image.endian);
	// my_mlx_pixel_put(&image, 5, 5, 0x00FF0000);
	draw(5, 100, 5, 100, &image, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.window, image.image, 0, 0);
	mlx_hook(vars.window, 2, 1L<<0, close_window, &vars);
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
