/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:18:00 by momil-vo          #+#    #+#             */
/*   Updated: 2024/06/06 21:14:00 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal_id	desired_fractal;

	if (argc != 2 && argc != 4)
		return (ft_input_error(INVALID_FRACTAL));
	desired_fractal = ft_get_fractal_id(argc, argv);
	if (desired_fractal.fractal_type == INVALID_FRACTAL)
		return (ft_input_error(desired_fractal.fractal_type));
	ft_manage_this_fractal(desired_fractal);
	return (0);
}

void	ft_engage_hooks(t_program_data	*all_data)
{
	t_mlx_data	mlx;

	mlx = all_data->mlx;
	mlx_hook(mlx.win, DestroyNotify, 0L, ft_its_closing_time, &mlx);
	mlx_expose_hook(mlx.win, ft_expose_hook, all_data);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, all_data);
	mlx_key_hook(mlx.win, ft_key_hook, all_data);
}

//gets the window started and contains the window loop
void	ft_manage_this_fractal(t_fractal_id this_fractal)
{
	t_mlx_data		mlx;
	t_img_data		img_var;
	t_program_data	all_data;

	mlx.width = DFLT_WIDTH;
	mlx.height = DFLT_HEIGHT;
	mlx.obj = mlx_init();
	if (mlx.obj == NULL)
		return ;
	mlx.win = mlx_new_window(mlx.obj, mlx.width, mlx.height, "fractol");
	if (mlx.win == NULL)
		ft_its_closing_time(&mlx);
	img_var.img = mlx_new_image(mlx.obj, mlx.width, mlx.height);
	img_var.adr = mlx_get_data_addr(img_var.img, &img_var.bpp,
			&img_var.line_length, &img_var.endian);
	if (img_var.bpp != 32 || img_var.endian != 0)
		ft_its_closing_time(&mlx);
	mlx.img_data = img_var;
	all_data.render = ft_draw_default_fractal(&mlx, this_fractal);
	all_data.mlx = mlx;
	ft_engage_hooks(&all_data);
	mlx_loop(mlx.obj);
}
