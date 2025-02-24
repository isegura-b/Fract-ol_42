/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:24:35 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/12 19:44:01 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1500
# define HEIGHT 1500

typedef struct s_complex
{
	double	x;
	double y; // i
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int bpp; // bits * pixel
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;

	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	// hooks
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void		error(char *msg);
int			ft_strncmp(char *s1, char *s2);
int			julia_error(char *av3, char	*av4);

void		data_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);

double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		atodbl(char *s);

void		handle_pixel(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

int			ft_keys(int keysym, t_fractal *fractal);
int			window_close(t_fractal *fractal);
int			ft_mouse(int button, int x, int y, t_fractal *fractal);

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

# define BLUE1 0x0D1F2D
# define BLUE2 0x1E3A5F
# define BLUE3 0x41729F
# define BLUE4 0x69A3D0
# define BLUE5 0xB3DDF2

#endif
