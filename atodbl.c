/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:28:25 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/04 17:30:29 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip_whitespace(char **str)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
}

static int	handle_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static double	parse_integer_part(char **str)
{
	double	result;

	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		result = (result * 10) + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	parse_decimal_part(char **str)
{
	double	decimal;
	int		count;

	decimal = 0;
	count = 0;
	if (**str == '.')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		decimal = (decimal * 10) + (**str - '0');
		count++;
		(*str)++;
	}
	return (decimal / pow(10, count));
}

double	atodbl(char *str)
{
	double	result;
	double	decimal;
	int		sign;

	skip_whitespace(&str);
	sign = handle_sign(&str);
	result = parse_integer_part(&str);
	decimal = parse_decimal_part(&str);
	return ((result + decimal) * sign);
}
