/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_pt_grid.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 17:03:02 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 13:11:52 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void free_tab(t_mem *mem)
{
	int		i;
	
	i = 0;
	while (i < mem->nb_y)
	{
		free(mem->tab[i]);
		i++;
	}
	free(mem->tab);
}

void		ft_get_pt_grid(t_mem *mem)
{
	int		i;
	int		j;

	i = 0;
	while (i < mem->nb_y)
	{
		j = 0;
		while (j < mem->nb_x)
		{
			mem->pt_grid[i][j].data[0] = j;
			mem->pt_grid[i][j].data[1] = i;
			mem->pt_grid[i][j].data[2] = mem->tab[i][j];
			j++;
		}	
		i++;
	}
}