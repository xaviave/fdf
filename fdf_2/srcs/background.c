/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   background.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 21:59:51 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 10:39:33 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_backgrounds(t_mem *mem)
{
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[0], "backgrounds/z4.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[1], "backgrounds/cyril.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[2], "backgrounds/xavplaymo.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[3], "backgrounds/kai.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[4], "backgrounds/augberna.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[5], "backgrounds/barbostar.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[6], "backgrounds/bodo.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[7], "backgrounds/darko.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[8], "backgrounds/leon.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[9], "backgrounds/leonthug.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[10], "backgrounds/louispls.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[11], "backgrounds/playmo.xpm");
}
