/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 13:37:40 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 13:21:14 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_optimize(t_affvars var, t_mem *mem)
{
	var.p1 = 0;
	var.p2 = 0;
	if (var.cx < 0)
		var.p1 += 8;
	else if (var.cx > mem->win.width)
		var.p1 += 4;
	if (var.cy < 0)
		var.p1 += 2;
	else if (var.cy > mem->win.height)
		var.p1 += 1;
	if (var.dx < 0)
		var.p1 += 8;
	else if (var.dx > mem->win.width)
		var.p1 += 4;
	if (var.dy < 0)
		var.p1 += 2;
	else if (var.dy > mem->win.height)
		var.p1 += 1;
	if (var.p1 != 0 && var.p2 != 0)
		if ((var.p1 & var.p2) != 0)
			return (0);
	return (1);
}

void	ft_disp_h(t_mem *mem)
{
	t_affvars	var;
	int			i;
	int			j;

	i = 0;
	while (i < mem->nb_y)
	{
		j = 0;
		while (j < mem->nb_x - 1)
		{
			var.cx = -mem->pt_grid[i][j].data[0] * mem->zoom + mem->x_offset;
			var.cy = -mem->pt_grid[i][j].data[1] * mem->zoom + mem->y_offset;
			var.dx = -mem->pt_grid[i][j + 1].data[0] * mem->zoom
				+ mem->x_offset;
			var.dy = -mem->pt_grid[i][j + 1].data[1] * mem->zoom
				+ mem->y_offset;
			var.color1 = mem->pt_grid[i][j].color;
			var.color2 = mem->pt_grid[i][j + 1].color;
			if (ft_optimize(var, mem))
				bresenham_gen(mem, var);
			j++;
		}
		i++;
	}
}

void	ft_disp_v(t_mem *mem)
{
	t_affvars	var;
	int			i;
	int			j;

	i = 0;
	while (i < mem->nb_y - 1)
	{
		j = 0;
		while (j < mem->nb_x)
		{
			var.cx = -mem->pt_grid[i][j].data[0] * mem->zoom + mem->x_offset;
			var.cy = -mem->pt_grid[i][j].data[1] * mem->zoom + mem->y_offset;
			var.dx = -mem->pt_grid[i + 1][j].data[0] * mem->zoom
				+ mem->x_offset;
			var.dy = -mem->pt_grid[i + 1][j].data[1] * mem->zoom
				+ mem->y_offset;
			var.color1 = mem->pt_grid[i][j].color;
			var.color2 = mem->pt_grid[i + 1][j].color;
			if (ft_optimize(var, mem))
				bresenham_gen(mem, var);
			j++;
		}
		i++;
	}
}

void	display(t_mem *mem)
{
	ft_disp_v(mem);
	ft_disp_h(mem);
}
