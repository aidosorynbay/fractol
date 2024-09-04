/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:30:33 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/04 22:10:57 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# define ESC 53
# define ERROR_MESSAGE_PART1 "Please enter \n\t\"./fractol mandelbrot\" or \n\t"
# define ERROR_MESSAGE_PART2 "\"./fractol julia <value_1> <value_2>\"\n"
# define MALLOC_ERROR "Malloc failed. Womp womp"
# define HEIGHT 800
# define WIDTH 800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	*name;
	int		boundary;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}				t_fractal;

typedef struct s_complex
{
	double	real;
	double	i;
}				t_complex;

// Basic Colors
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define GREY	0x333333
# define DARK_GREY			0x1c1c1c
# define DARKER_GREY		0x1a1a1a
# define PSYCHEDELIC_GREEN	0x32CD32  // Lime Green
# define PSYCHEDELIC_YELLOW	0xFFFF00  // Bright Yellow
# define PSYCHEDELIC_ORANGE	0xFF4500  // Orange Red
# define PSYCHEDELIC_BLUE	0x1E90FF  // Dodger Blue
# define PSYCHEDELIC_CYAN	0x00FFFF  // Cyan
# define PSYCHEDELIC_RED	0xFF0000  // Bright Red
# define PSYCHEDELIC_LIME	0x00FF00  // Bright Lime

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	atodbl(char *str);
double	scaling(double u_n, double new_min, double new_max, double old_max);
void	fractol_events(t_fractal *fractal);
int		check_float(char *str);

#endif 