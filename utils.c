/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:54:19 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/03 20:11:32 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"

double	atodbl(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		count;

	result = 0;
	decimal = 0;
	sign = 1;
	count = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str != '.')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		decimal = (decimal * 10) + (*str - '0');
		count++;
		str++;
	}
	decimal = decimal / pow(10, count);
	result = result + decimal;
	return (result * sign);
}

double	scaling(double u_n, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (u_n - 0) / (old_max - 0) + new_min);
}

t_complex	sum_c(t_complex z, t_complex c)
{
	t_complex	res;
	res.real = z.real + c.real;
	res.i = z.i + c.i;
	return (res);
}

t_complex	square_c(t_complex z)
{
	t_complex	res;
	
	res.real = pow(z.real, 2) - pow(z.i, 2);
	res.i = 2 * z.i * z.real;
	return (res);
}
