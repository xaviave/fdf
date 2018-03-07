/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   background.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 21:59:51 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 22:33:46 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_backgrounds(t_mem *mem)
{
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[0], "backgrounds/cyril.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[1], "backgrounds/xavplaymo.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[2], "backgrounds/kai.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[3], "backgrounds/augberna.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[4], "backgrounds/barbostar.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[5], "backgrounds/bodo.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[6], "backgrounds/darko.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[7], "backgrounds/leon.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[8], "backgrounds/leonthug.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[9], "backgrounds/louispls.xpm");
	ft_create_xpm_img(mem->mlx_ptr,
		&mem->backbanck[10], "backgrounds/playmo.xpm");
}
