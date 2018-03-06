/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:57:16 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 16:54:11 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mod_z(t_mem *mem, int f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < mem->nb_y)
	{
			j = 0;
			while (j <  mem->nb_x)
			{
				if (f == 1)
					mem->tab[i][j] *= 2;
				if (f == 0)
					mem->tab[i][j] /= 2;
				j++;
			}
			i++;
	}
}
int		ft_init(t_mem *mem)
{
	mem->theta = 0;
	mem->alpha = M_PI_4;
	mem->win.width = 1800;
	mem->win.height = 900;
	mem->zoom = 20;
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
	if (key == TOUCH_NUMPAD_LESS && mem->zoom > 1)
		mem->zoom /= 2;
	if (key == TOUCH_NUMPAD_PLUS)
		mem->zoom *= 2;
	if (key == TOUCH_RIGHT)
		mem->x_offset += 100;
	if (key == TOUCH_NUMPAD_4)
		mod_z(mem, 0);
	if (key == TOUCH_NUMPAD_5)
		mod_z(mem, 1);
	if (key == TOUCH_LEFT)
		mem->x_offset -= 100;
	if (key == TOUCH_UP)
		mem->y_offset -= 100;
	if (key == TOUCH_DOWN)
		mem->y_offset += 100;
	if (key == TOUCH_A)
	{
		mem->theta -= 1;
		if (mem->theta < -16)
			mem->theta += 32;
		if (mem->theta > 16)
			mem->theta -= 32;
	}
	if (key == TOUCH_S)
	{
		mem->theta += 1;
		if (mem->theta < -16)
			mem->theta += 32;
		if (mem->theta > 16)
			mem->theta -= 32;
	}
	if (key == TOUCH_Q)
	{
		mem->alpha -= 1;
		if (mem->alpha < -16)
			mem->alpha += 32;
		if (mem->alpha > 16)
			mem->alpha -= 32;
	}
	if (key == TOUCH_W)
	{
		mem->alpha += 1;
		if (mem->alpha < -16)
			mem->alpha += 32;
		if (mem->alpha > 16)
			mem->alpha -= 32;
	}
	if (key == TOUCH_ECHAP)
		exit(1);
	printf("%f\n", mem->theta);
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_create_img(mem);
	ft_main_loop(mem);
	return (0);
}

int			main(int ac, char **av)
{
	t_mem	*mem;
	int		j;
	int		i;

	mem = (t_mem *)malloc(sizeof(t_mem));
	mem->color1.r = 155;
	mem->color1.g = 155;
	mem->color1.b = 155;
	mem->color1.a = 0;
	mem->color2.r = 0;
	mem->color2.g = 204;
	mem->color2.b = 255;
	mem->color2.a = 0;
	mem->colora.r = 0;
	mem->colora.g = 0;
	mem->colora.b = 0;
	mem->colora.a = 0;
	mem->colorb.r = 255;
	mem->colorb.g = 0;
	mem->colorb.b = 0;
	mem->colorb.a = 0;
	mem->colorc.r = 0;
	mem->colorc.g = 255;
	mem->colorc.b = 0;
	mem->colorc.a = 0;
	mem->colord.r = 0;
	mem->colord.g = 0;
	mem->colord.b = 255;
	mem->colord.a = 0;
	i = 0;
	ft_init(mem);
	if (ac == 2)
	{
		parse(mem, av[1]);
		mem->pt_grid = (t_pt **)malloc(sizeof(t_pt *) * mem->nb_y);
		while (i < mem->nb_y)
		{
			j = 0;
			mem->pt_grid[i] = (t_pt *)malloc(sizeof(t_pt) * mem->nb_x);
			while (j <  mem->nb_x)
			{
				mem->pt_grid[i][j].color = pt_color(mem, i, j);
				j++;
			}
			i++;
		}
		ft_main_loop(mem);
		//ft_mtx_display(&mem);
	}
	mlx_key_hook(mem->win.win_ptr, ft_key, mem);
	mlx_loop(mem->mlx_ptr);
	return (0);
}
