/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:17:45 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/24 01:15:44 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int len(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{	
		i++;
	}
	return (i);
}

static int is_not_num(char *n)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while ((n[i] >= '0' && n[i] <= '9') || n[i] == '.')
	{
		if (n[i] == '.')
		{
			if (flag != 0)
				return (1);
			flag++;
		}
		i++;
	}
	if (i == len(n) && i != 0)
		return (0);
	return (1);
}

static int inside_lim(char *n)
{
	char	*min;
	char	*max;

	min = "-2";
	max = "2";
	if (atodbl(n) >= atodbl(min) && atodbl(n) <= atodbl(max))
		return (0);
	return (1);
}

int	julia_error(char *n1, char *n2)
{
	if (is_not_num(n1) || is_not_num(n2) || inside_lim(n1) || inside_lim(n2))
		return (1);
	return (0);
}
