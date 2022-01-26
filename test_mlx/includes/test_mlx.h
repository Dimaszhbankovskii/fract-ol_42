#ifndef TEST_MLX
# define TEST_MLX

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

typedef struct s_main
{
	void			*mlx;
	void			*window;
	t_image			image;
	t_complex		max;
	t_complex		min;
	unsigned int	colot;
	t_complex		unit_vector;
	t_complex		vector;
	unsigned int	color_shift;
	double			bright_shift;
	unsigned int	((*formula_fractol)(struct s_main *obj));
}				t_main;

t_complex		init_complex(double re, double im);
void			set_default_obj(t_main *obj);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
void			draw_obj(t_main *obj);
unsigned int	make_obj(t_main *obj);
int				zoom(int keycode, int x, int y, t_main *obj);
int				move_image(int keycode, t_main *obj);
int				press_key(int keycode, t_main *obj);

// int				get_color(unsigned int iteration, t_fractol *fractol);
// int				press_key(int keycode, t_fractol *fractol);


#endif