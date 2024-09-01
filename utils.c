/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:54:19 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/01 20:15:07 by aorynbay         ###   ########.fr       */
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
	}
	decimal = decimal / pow(10, count);
	result = result + decimal;
	return (result * sign);
}
