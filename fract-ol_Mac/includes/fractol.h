#ifndef FRACTOL
# define FRACTOL

# include <mlx.h>
# include <math.h>

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_image
{
	void	*image;
	char	*address;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_complex	max;
	t_complex	min;
	t_complex	unit_vector;
	t_complex	vector;
}				t_fractol;

t_complex	init_complex(double re, double im);


#endif