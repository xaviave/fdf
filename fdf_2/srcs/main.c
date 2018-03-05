/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:57:16 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 13:17:55 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
# include <stdio.h>

int		ft_init(t_mem *mem)
{
	mem->theta = M_PI_4;
	mem->alpha = M_PI_4;
	mem->win.width = 1800;
	mem->win.height = 900;
	mem->zoom = 100;
	mem->mlx_ptr = mlx_init();
	mem->win.win_ptr = mlx_new_window(mem->mlx_ptr, mem->win.width, mem->win.height, "fdf");
	ft_create_img(mem);
	return (1);
}

void	ft_main_loop(t_mem *mem)
{
	ft_matrix_compute(mem);
	display(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

int		ft_key(int key, t_mem *mem)
{
	if (key == TOUCH_NUMPAD_LESS)
		mem->zoom -= 10;
	if (key == TOUCH_NUMPAD_PLUS)
		mem->zoom += 10;
	if (key == TOUCH_RIGHT)
		mem->x_offset += 100;
	if (key == TOUCH_LEFT)
		mem->x_offset -= 100;
	if (key == TOUCH_UP)
		mem->y_offset -= 100;
	if (key == TOUCH_DOWN)
		mem->y_offset += 100;
	if (key == TOUCH_A)
		mem->theta -= M_PI_4 / 4;
	if (key == TOUCH_S)
		mem->theta += M_PI_4 / 4;
	if (key == TOUCH_Q)
		mem->alpha -= M_PI_4 / 4;
	if (key == TOUCH_W)
		mem->alpha += M_PI_4 / 4;
	if (key == TOUCH_ECHAP)
		exit(1);
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_create_img(mem);
	ft_main_loop(mem);
	return (0);
}

int			main(int ac, char **av)
{
	t_mem	*mem;
	int i;

	mem = (t_mem *)malloc(sizeof(t_mem));
	mem->color.r = 0;
	mem->color.g = 254;
	mem->color.b = 104;
	mem->color.a = 0;
	i = 0;
	ft_init(mem);
	if (ac == 2)
	{
		parse(mem, av[1]);
		mem->pt_grid = (t_pt **)malloc(sizeof(t_pt *) * mem->nb_y);
		while (i < mem->nb_y)
			mem->pt_grid[i++] = (t_pt *)malloc(sizeof(t_pt) * mem->nb_x);
		ft_main_loop(mem);
		//ft_mtx_display(&mem);
	}
	mlx_key_hook(mem->win.win_ptr, ft_key, mem);
	mlx_loop(mem->mlx_ptr);
	return (0);
}
