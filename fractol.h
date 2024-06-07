/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 23:05:07 by momil-vo          #+#    #+#             */
/*   Updated: 2024/06/06 21:06:22 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

# define DFLT_WIDTH 900
# define DFLT_HEIGHT 900
# define INVALID_FRACTAL -1
# define UNESPECIFIED_FRACTAL 0
# define JULIA 1
# define MANDELBROT 2
# define BURN_SHIP 3
# define DF_RADIUS 2
# define INPUT_ERROR_MSG "Input error\n\nUsage:\n\
./fractol Julia [Re(c)] [Im(c)]\n\
	[Re(c)] and [Im(c)] are decimal numbers\n\
./fractol Mandelbrot\n\
./fractol Burningship\n"
# define OUT_COLOR_A 0xAA8000
# define OUT_COLOR_B 0xAA20AA
# define IN_COLOR 0x000000
# define DF_MIN_RE -2
# define DF_MAX_RE +2
# define DF_MIN_IM -2
# define DF_MAX_IM +2
# define ZOOM 0.25
# define MOVE_RATIO 0.5
# define DIR_R 1
# define DIR_L 2
# define DIR_U 3
# define DIR_D 4
# define DF_NBR_ITER 100
# define VARIABLE_NBR_ITER 0
# define R_CLICK 1
# define L_CLICK 3
# define SCROL_U 4
# define SCROL_D 5
# define COLOR_ALGTHM 1
//only for Julia Sets (use 1 or -1)
# define REAL_AXIS_DIR 1

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img_data
{
	void	*img;
	char	*adr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_mlx_data
{
	void		*obj;
	void		*win;
	int			width;
	int			height;
	t_img_data	img_data;
}	t_mlx_data;

typedef struct s_fractal_id
{
	int			fractal_type;
	double		c_re;
	double		c_im;
	float		scape_radius;
}	t_fractal_id;

typedef struct s_render_data
{
	t_fractal_id	fractal_id;
	double			max_re;
	double			min_re;
	double			max_im;
	double			min_im;
	unsigned int	n_rows;
	unsigned int	n_clms;
	unsigned int	max_iter;
}	t_render_data;

typedef struct s_program_data
{
	t_render_data	render;
	t_mlx_data		mlx;
}	t_program_data;

void			ft_manage_this_fractal(t_fractal_id this_fractal);
int				ft_input_error(int fractal_type);
t_fractal_id	ft_get_fractal_id(int argc, char **argv);
long double		ft_atold(char *str);
int				ft_its_closing_time(t_mlx_data *mlx_data);
int				ft_key_hook(int keysym, t_program_data *all);
int				ft_mouse_hook(int button, int x, int y, t_program_data *all);
int				ft_expose_hook(t_program_data *all);
float			ft_scape_radius(t_fractal_id fractal);
int				ft_in_bounds(t_fractal_id fractal, t_complex z, int quick);
t_render_data	ft_draw_default_fractal(t_mlx_data *mlx_data,
					t_fractal_id fractal_id);
void			ft_draw_fractal(t_mlx_data *mlx_data,
					t_render_data render_data);
void			ft_draw_in_adress(t_mlx_data *mlx_data,
					t_render_data render_data);
uint32_t		ft_get_color(t_render_data rdr, t_complex z);
double			ft_square_modulo(t_complex z);
t_complex		ft_fractal_opperation(
					int fractal_type, t_complex z, t_complex c);
uint8_t			ft_get_t(uint32_t trgb);
uint8_t			ft_get_r(uint32_t trgb);
uint8_t			ft_get_g(uint32_t trgb);
uint8_t			ft_get_b(uint32_t trgb);
uint32_t		ft_trgb_to_color(uint8_t t, uint8_t r, uint8_t g, uint8_t b);
t_complex		ft_build_complex(double long re, double long im);

#endif
