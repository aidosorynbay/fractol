/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:48:35 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/04 22:12:20 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	char		*error_message;

	error_message = ERROR_MESSAGE_PART1 ERROR_MESSAGE_PART2;
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			if (check_float(argv[2]) && check_float(argv[3]))
			{
				fractal.julia_x = atodbl(argv[2]);
				fractal.julia_y = atodbl(argv[3]);
			}
			else
				(ft_putstr_fd(error_message, 2), exit(1));
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		fractol_events(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		(ft_putstr_fd(error_message, 2), exit(1));
}
