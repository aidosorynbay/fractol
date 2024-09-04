/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:00 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/02 17:47:00 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->img_pixels_ptr + offset) = color;
}

static void	julia_or_man(t_fractal *fractal, t_complex *z, t_complex *c)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
	{
		c->real = fractal->julia_x;
		c->i = fractal->julia_y;
	}
	else
		*c = *z;
}

static void	put_pixel(int x, int y, t_fractal *fractal, int i)
{
	t_complex	z;
	t_complex	c;
	int			color;
	double		z_real_squared;
	double		z_imag_squared;

	z.real = scaling(x, fractal->x_min, fractal->x_max, WIDTH);
	z.i = scaling(y, fractal->y_min, fractal->y_max, HEIGHT);
	julia_or_man(fractal, &z, &c);
	while (i < fractal->iterations)
	{
		z_real_squared = z.real * z.real;
		z_imag_squared = z.i * z.i;
		if (z_real_squared + z_imag_squared > fractal->boundary)
		{
			color = scaling(i, DARK_GREY, DARKER_GREY, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		z.i = 2 * z.real * z.i + c.i;
		z.real = z_real_squared - z_imag_squared + c.real;
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	fractal->x_min = -2 / fractal->zoom + fractal->shift_x;
	fractal->x_max = 2 / fractal->zoom + fractal->shift_x;
	fractal->y_min = 2 / fractal->zoom + fractal->shift_y;
	fractal->y_max = -2 / fractal->zoom + fractal->shift_y;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, fractal, i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->win_ptr, fractal->img.img_ptr, 0, 0);
}
