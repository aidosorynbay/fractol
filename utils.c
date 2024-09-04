/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:54:19 by aorynbay          #+#    #+#             */
/*   Updated: 2024/09/04 20:29:18 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"

static void	skip_space(char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

int	check_float(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	skip_space(str, &i);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '.' && ft_isdigit(str[i - 1])
			&& ft_isdigit(str[i + 1]))
		{
			i++;
			count++;
		}
		else if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
			i++;
		else
			return (0);
	}
	if (str[i] == '\0' && count <= 1)
		return (1);
	return (0);
}

double	scaling(double u_n, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (u_n - 0) / (old_max - 0) + new_min);
}
