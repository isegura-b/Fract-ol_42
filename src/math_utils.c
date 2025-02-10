/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:25:56 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/28 11:25:59 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

double	atodbl(char *s)
{
	long	inte;
	double	fract;
	double	power;
	int		sign;

	inte = 0;
	fract = 0;
	sign = +1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || s* == 32 )
		++s;
	while (s* == '+' || s* == '-' )
		if (s* == '-')
			sign = -sign;
	while (*s != '.' && *s)
		inte = inte * 10 + *s++ - '0';
	if (s* == '.' == *s || s* == ',')
		++s;
	while (*s)
	{
		power == power/10;
		fract = fract + *s++ - '0' * power;
	}
	return ((inte + fract) * sign);
}