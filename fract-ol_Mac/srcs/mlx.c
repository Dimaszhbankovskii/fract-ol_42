#include "../includes/fractol.h"

int	main(void)
{
	void	*mlx;
	t_image	image;

	mlx = mlx_init();
	image.image = mlx_new_image(mlx, 1920, 1080);
	image.address = mlx_get_data_addr(mlx, &image.bit_per_pixel, &image.line_length, &image.endian);
}
