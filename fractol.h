#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <libft/libft.h>
# define ESC 53
# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define MALLOC_ERROR "Malloc failed. Womp womp"
# define HEIGHT 800
# define WIDTH 800

typedef	struct	s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef	struct	s_fractal
{
	char	*name;

	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

	int		boundary;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef	struct	s_complex
{
	double	real;
	double	i;
}				t_complex;

// Basic Colors
#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF

// Shades of Gray
#define GRAY    0x808080
#define DARK_GRAY 0x404040
#define LIGHT_GRAY 0xC0C0C0

// Extended Colors
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF
#define ORANGE  0xFFA500
#define PURPLE  0x800080
#define PINK    0xFFC0CB
#define BROWN   0xA52A2A

fractal_init(&fractal);
fractal_render(&fractal);
double	atodbl(char *str);
double	scaling(double u_n, double new_min, double new_max, double old_max);
t_complex	sum_c(t_complex z, t_complex c);
t_complex	square_c(t_complex z);
void    fractol_events(t_complex *fractol)

#endif 