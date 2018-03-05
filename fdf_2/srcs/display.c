/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 13:37:40 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 13:11:45 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			var.dx = -mem->pt_grid[i][j + 1].data[0] * mem->zoom + mem->x_offset;
			var.dy = -mem->pt_grid[i][j + 1].data[1] * mem->zoom + mem->y_offset;
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
			var.dx = -mem->pt_grid[i + 1][j].data[0] * mem->zoom + mem->x_offset;
			var.dy = -mem->pt_grid[i + 1][j].data[1] * mem->zoom + mem->y_offset;
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