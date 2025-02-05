/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:26:07 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/05 17:57:00 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

//colores fractal


void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	c.x = fractal->zoom * (map(x, -2, +2, WIDTH)) + fractal->shift_x;
	c.y = fractal->zoom * (map(y, +2, -2, HEIGHT)) + fractal->shift_y;
	i = 0;
	my_pixel_put(x, y, &fractal->img, BLACK);
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value && (i % 5) == 1)
		{
			my_pixel_put(x, y, &fractal->img, BLUE2);
		}
		else if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value && (i
				% 5) == 2)
		{
			my_pixel_put(x, y, &fractal->img, BLUE3);
		}
		else if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value && (i
				% 5) == 3)
		{
			my_pixel_put(x, y, &fractal->img, BLUE4);
		}
		else if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value && (i
				% 5) == 4)
		{
			my_pixel_put(x, y, &fractal->img, BLUE5);
		}
		else if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value && (i
				% 5) == 0)
		{
			my_pixel_put(x, y, &fractal->img, BLUE1);
		}
		i++;
	}
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
