/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:25:29 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/24 00:29:15 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot"))
			|| (ac == 4 && !ft_strncmp(av[1], "julia")
			   && !julia_error(av[2], av[3])))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia"))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		write(1, "     Incorrect fractal name\n", 29);	
		write(1, "     try ./fractol mandelbrot\n", 31);
		write(1, "     or ./fractol julia real i\n", 32);
		write(1, "     were real and im are number -2<+2\n", 39);
		write(1, "     with decimals separated by a .\n", 36);
		exit(EXIT_FAILURE);
	}
}
