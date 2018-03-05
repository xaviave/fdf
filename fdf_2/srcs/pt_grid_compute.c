/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pt_grid_compute.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:46:48 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 13:11:40 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	pt_time_mtx(t_pt *pt, t_mtx mtx)
{
	float 	tmp[3];
	int		i;
	int		j;

	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			tmp[i] += pt->data[j] * mtx.data[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	pt->data[0] = tmp[0];
	pt->data[1] = tmp[1];
	pt->data[2] = tmp[2];	
}

static void	pt_grid_compute(t_mem *mem, t_mtx *mtx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mem->nb_y)
	{
		j = 0;
		while (j < mem->nb_x)
		{
			mem->pt_grid[i][j].data[0] = (float)j - ((float)mem->nb_x / 2.0);
			mem->pt_grid[i][j].data[1] = (float)i - ((float)mem->nb_y / 2.0);
			mem->pt_grid[i][j].data[2] = (float)mem->tab[i][j];
			pt_time_mtx(&mem->pt_grid[i][j], *mtx);
			j++;
		}
		i++;
	}
}

static void	ft_init_mtx(t_mem *mem, t_mtx *mtx)
{
	mtx->data[0][0] = cos(mem->theta + M_PI_2);
	mtx->data[1][0] = sin(mem->theta + M_PI_2);
	mtx->data[2][0] = 0;
	mtx->data[0][2] = - (cos(mem->alpha) * cos(mem->theta));
	mtx->data[1][2] = - (cos(mem->alpha) * sin(mem->theta));
	mtx->data[2][2] = - (sin(mem->alpha));
	mtx->data[0][1] = (mtx->data[1][0] * mtx->data[2][2]) - (mtx->data[2][0] * mtx->data[1][2]);
	mtx->data[1][1] = (mtx->data[2][0] * mtx->data[0][2]) - (mtx->data[0][0] * mtx->data[2][2]);
	mtx->data[2][1] = (mtx->data[0][0] * mtx->data[1][2]) - (mtx->data[1][0] * mtx->data[0][2]);
}


void		ft_matrix_compute(t_mem *mem)
{
	t_mtx	*mtx;
	t_mtx	*mtx2;
	t_mtx	*comm;
	t_mtx	*transpo;
	float	det;
	
	mtx = (t_mtx *)malloc(sizeof(t_mtx));
	ft_mtx_build(mtx, 3, 3, 0);
	ft_init_mtx(mem, mtx);
	det = ft_mtx_det(*mtx);
	comm = ft_mtx_com(*mtx);
	transpo = ft_mtx_trans(*comm);
	mtx2 = ft_mtx_times_scal(*transpo, 1.0 / det);
	pt_grid_compute(mem, mtx2);
	ft_mtx_destroy(mtx2);
	ft_mtx_destroy(transpo);
}