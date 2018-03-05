/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_display.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 11:14:25 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 13:29:33 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>



void	ft_mtx_display(t_mem *mem)
{
	int	i;
	int	j;

	i = 0;
	while (i < mem->nb_y)
	{
		j = 0;
		printf("linge %d\n", i);
		while (j < mem->nb_x)
		{
			printf("%d, \n", mem->tab[i][j]);
			printf("x = %f, y = %f, z = %f\n", mem->pt_grid[i][j].data[0], mem->pt_grid[i][j].data[1], mem->pt_grid[i][j].data[2]);
			j++;
		}
		i++;
	}
}
