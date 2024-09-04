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

static void    my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->img_pixels_ptr + offset) = color;
}

static void put_pixel(int x, int y, t_fractal *fractal, double x_min, double x_max, double y_min, double y_max)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    z.real = scaling(x, x_min, x_max, WIDTH);
    z.i = scaling(y, y_min, y_max, HEIGHT);
    if (!ft_strncmp(fractal->name, "julia", 6))
    {
        c.real = fractal->julia_x;
        c.i = fractal->julia_y;
    }
    else
        c = z;
    while (i < fractal->iterations)
    {
        double z_real_squared = z.real * z.real;
        double z_imag_squared = z.i * z.i;

        if (z_real_squared + z_imag_squared > fractal->boundary)
        {
            color = scaling(i, BLACK, WHITE, fractal->iterations);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }

        z.i = 2 * z.real * z.i + c.i;
        z.real = z_real_squared - z_imag_squared + c.real;

        i++;
    }
    my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_RED);
}



void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;
    double x_min;
    double x_max;
    double y_min;
    double y_max;

    y = 0;
    x_min = -2 / fractal->zoom + fractal->shift_x;
    x_max = 2 / fractal->zoom + fractal->shift_x;
    y_min = 2 / fractal->zoom + fractal->shift_y;
    y_max = -2 / fractal->zoom + fractal->shift_y;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            put_pixel(x, y, fractal, x_min, x_max, y_min, y_max);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img.img_ptr, 0, 0);
}
