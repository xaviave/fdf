/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_manage.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:06:54 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 15:13:29 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mod_z(t_mem *mem, int f)
{
	int		i;
	int		j;

	i = 0;
	j = 0					;
	while (i < mem->nb_y)
	{
		j = 0;
		while (j < mem->nb_x)
		{
			if (f == 1)
				mem->tab[i][j] *= 2;
			if (f == 0)
				mem->tab[i][j] /= 2;
			j++;
		}
		i++;
	}
}

static void	key_angle(t_mem *mem, int key)
{
	if (key == TOUCH_A)
		mem->theta -= M_PI_4 / 4;
	if (key == TOUCH_S)
		mem->theta += M_PI_4 / 4;
	if (key == TOUCH_Q)
		mem->alpha -= M_PI_4 / 4;
	if (key == TOUCH_W)
		mem->alpha += M_PI_4 / 4;
}

int			ft_key(int key, t_mem *mem)
{
	if (key == TOUCH_NUMPAD_LESS && mem->zoom > 1)
		mem->zoom /= 2;
	if (key == TOUCH_NUMPAD_PLUS)
		mem->zoom *= 2;
	if (key == TOUCH_RIGHT)
		mem->x_offset += 100;
	if (key == TOUCH_NUMPAD_4)
		mod_z(mem, 0);
	if (key == TOUCH_NUMPAD_5)
		mod_z(mem, 1);
	if (key == TOUCH_LEFT)
		mem->x_offset -= 100;
	if (key == TOUCH_UP)
		mem->y_offset -= 100;
	if (key == TOUCH_DOWN)
		mem->y_offset += 100;
	if (key == TOUCH_ECHAP)
		exit(1);
	key_angle(mem, key);
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_create_img(mem);
	ft_main_loop(mem);
	return (0);
}
