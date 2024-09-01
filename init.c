/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:31:29 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/01 19:49:25 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"

void	data_init(t_fractal *fractal)
{
	fractal->bound = 4;
	fractal->iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		exit(1);
	}
	fractal->win_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, NULL);
		free(fractal->mlx_ptr);
		ft_putstr_fd(MALLOC_ERROR, 2);
		exit(1);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_image(fractal->mlx_ptr, NULL);
		mlx_destroy_window(fractal->mlx_ptr, NULL);
		free(fractal->mlx_ptr);
		ft_putstr_fd(MALLOC_ERROR, 2);
		exit(1);
	}
	fractal->img.img_pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pixel, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
}
