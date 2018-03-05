/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_trans.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 22:19:48 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 09:54:19 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

t_mtx	*ft_mtx_trans(t_mtx mtx)
{
	t_mtx *tmp;
	int i;
	int j;
	int a;
	int b;

	i = 0;
	j = 0;
	a = 0;
	b = 0;
	tmp = (t_mtx *)malloc(sizeof(t_mtx)); 
	ft_mtx_build(tmp, mtx.m, mtx.n, 0);
	while (i < mtx.m)
	{
		while (j < mtx.n)
		{
			tmp->data[i][j] = mtx.data[a][b];
			a++;
			j++;
		}
		a = 0;
		b++;
		j = 0;
		i++;
	}
	return (tmp);
}
