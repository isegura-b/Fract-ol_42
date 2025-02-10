/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:25:03 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/28 11:56:29 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(char *msg)
{
	while (*msg)
	{
		write(1, &msg, 1);
		msg++;
	}
	exit(EXIT_FAILURE);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (NULL == s1 || NULL == s2)
		return (0);
	while (s1[i] == s2[i] && n > 0 && *s1 != '\0')
	{
		++i;
		--n;
	}
	return (*s1 - *s2);
}
