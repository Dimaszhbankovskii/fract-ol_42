#ifndef FRACTOL
# define FRACTOL

# include "../libft/libft.h"
# include "keycode_mac.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 800

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
	void			*mlx;
	void			*window;
	t_image			image;
	t_complex		max;
	t_complex		min;
	unsigned int	max_iteration;
	t_complex		unit_vector;
	t_complex		vector;
	unsigned int	color_shift;
	double			bright_shift;
	unsigned int	((*formula_fractol)(struct s_fractol *fractol));
}				t_fractol;

t_complex		init_complex(double re, double im);
void			set_default_fractol(t_fractol *fractol);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
void			draw_fractol(t_fractol *fractol);
unsigned int	init_mandelbrot(t_fractol *fractol);
int				get_color(unsigned int iteration, t_fractol *fractol);
int				press_key(int keycode, t_fractol *fractol);


#endif