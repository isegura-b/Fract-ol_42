/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:25:29 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/28 11:58:17 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
    t_fractal   fractal;

    if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
        || (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
    {
        fractal.name = av[1];
        fractal_init(&fractal);
        fractal_render(&fractal);


        mlx_loop(fractal.mlx_connection);
    }
    else
        write(1, "Incorrect fractal name\n", 24);
}
