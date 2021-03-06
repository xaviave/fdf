/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:57:16 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/06 15:38:59 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_fill_image(t_mem *mem)
{
	int		i;
	int		j;
	t_color	color;

	i = 0;
	j = 0;
	color.r = 0;
	color.g = 0;
	color.g = 0;
	color.a = 255;
	while (i < 900)
	{
		while (j < 1800)
		{
			ft_put_pixel(mem, color, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

static int	ft_init(t_mem *mem)
{
	mem->color1.r = 52;
	mem->color1.g = 52;
	mem->color1.b = 255;
	mem->color1.a = 0;
	mem->color2.r = 204;
	mem->color2.g = 204;
	mem->color2.b = 0;
	mem->color2.a = 0;
	mem->backid = 0;
	mem->theta = 4;
	mem->alpha = 4;
	mem->win.width = 1800;
	mem->win.height = 900;
	mem->zoom = 10;
	mem->x_offset = mem->win.width / 2;
	mem->y_offset = mem->win.height / 2;
	mem->mlx_ptr = mlx_init();
	mem->win.win_ptr = mlx_new_window(mem->mlx_ptr, mem->win.width,
			mem->win.height, "fdf");
	ft_create_img(mem);
	ft_init_backgrounds(mem);
	return (1);
}

static int	ft_error(void)
{
	ft_putstr("Usage fdf: ./fdf [maps.fdf]\n");
	return (0);
}

void		ft_main_loop(t_mem *mem)
{
	ft_matrix_compute(mem);
	ft_fill_image(mem);
	display(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr,
		mem->backbanck[mem->backid].ptr, 0, 0);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

int			main(int ac, char **av)
{
	t_mem	*mem;
	int		j;
	int		i;

	if (ac != 2)
		return (ft_error());
	mem = (t_mem *)malloc(sizeof(t_mem));
	i = 0;
	parse(mem, av[1]);
	ft_init(mem);
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
