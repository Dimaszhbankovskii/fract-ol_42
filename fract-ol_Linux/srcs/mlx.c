#include "../includes/fractol.h"

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

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_image	image;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 800, 400, "Fractol");
	image.image = mlx_new_image(mlx, 800, 400);
	image.address = mlx_get_data_addr(image.image, &image.bit_per_pixel, &image.line_length, &image.endian);
	// my_mlx_pixel_put(&image, 5, 5, 0x00FF0000);
	draw(5, 100, 5, 100, &image, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_window, image.image, 0, 0);
	mlx_loop(mlx);
	return (0);
}
