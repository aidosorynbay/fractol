/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:35:16 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/02 21:35:16 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"

static int closer_f(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
    (void)(fractal);
    exit(1);
}

static int  mouse_f(int button, int x, int y, t_fractal *fractal)
{
    (void)(x);
    (void)(y);
    if (button == 4)
        fractal->zoom *= 1.05;
    else if (button == 5)
        fractal->zoom *= 0.95;
    fractal_render(fractal);
    return (0);
}

static int  key_f(int keysym, t_fractal *fractal)
{
    if (keysym == ESC)
        closer_f(fractal);
    else if (keysym == 123) // left
    {
        fractal->shift_x -= 0.1 / fractal->zoom;
    }
    else if (keysym == 124) // right
    {
        fractal->shift_x += 0.1 / fractal->zoom;
    }
    else if (keysym == 126) // up
    {
        fractal->shift_y += 0.1 / fractal->zoom;
    }
    else if (keysym == 125) // down
    {
        fractal->shift_y -= 0.1 / fractal->zoom;
    }
    fractal_render(fractal);
    return (0);
}

void    fractol_events(t_fractal *fractal)
{
    mlx_hook(fractal->win_ptr, 4, 0, mouse_f, fractal);
    mlx_hook(fractal->win_ptr, 2, 0, key_f, fractal);
}