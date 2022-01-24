#ifndef FRACTOL
# define FRACTOL

# include <mlx.h>

typedef struct s_image
{
	void	*image;
	char	*address;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

#endif