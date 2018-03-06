/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:57:16 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:16:48 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_init(t_mem *mem)
{
	mem->color1.r = 159;
	mem->color1.g = 46;
	mem->color1.b = 255;
	mem->color1.a = 100;
	mem->color2.r = 159;
	mem->color2.g = 155;
	mem->color2.b = 255;
	mem->color2.a = 0;
	mem->theta = 4;
	mem->alpha = 4;
	mem->win.width = 800;
	mem->win.height = 900;
	mem->zoom = 10;
	mem->x_offset = mem->win.width / 2;
	mem->y_offset = mem->win.height / 2;
	mem->mlx_ptr = mlx_init();
	mem->win.win_ptr = mlx_new_window(mem->mlx_ptr, mem->win.width,
			mem->win.height, "fdf");
	ft_create_img(mem);
	return (1);
}

void		ft_main_loop(t_mem *mem)
{
	ft_matrix_compute(mem);
	display(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

int			main(int ac, char **av)
{
	t_mem	*mem;
	int		j;
	int		i;

	if (ac != 2)
		return (0);
	mem = (t_mem *)malloc(sizeof(t_mem));
	i = 0;
	ft_init(mem);
	parse(mem, av[1]);
	mem->pt_grid = (t_pt **)malloc(sizeof(t_pt *) * mem->nb_y);
	while (i < mem->nb_y)
	{
		j = -1;
		mem->pt_grid[i] = (t_pt *)malloc(sizeof(t_pt) * mem->nb_x);
		while (++j < mem->nb_x)
			mem->pt_grid[i][j].color = pt_color(mem, i, j);
		i++;
	}
	ft_main_loop(mem);
	mlx_key_hook(mem->win.win_ptr, ft_key, mem);
	mlx_loop(mem->mlx_ptr);
	return (1);
}
