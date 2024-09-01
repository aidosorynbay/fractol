#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
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

	int		bound;
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


#endif 