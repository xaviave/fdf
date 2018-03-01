/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 17:44:36 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 14:46:45 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static void		free_tab(t_tab *tab)
{
	int			i;
	int			j;

	i = 0;
	if (!(tab->p = (t_p **)malloc(sizeof(t_p *) * tab->nb_y + 1)))
		return ;
	while (i < tab->nb_y)
	{
		j = 0;
		if (!(tab->p[i] = (t_p *)malloc(sizeof(t_p) * tab->nb_x + 1)))
			return ;
		while (j < tab->nb_x)
		{
			tab->p[i][j].h = tab->tab[i][j];
			j++;
		}
		i++;
		free(tab->tab[i]);
	}
	free(tab->tab);
}

static void		put_pixel(t_tab *tab)
{
	int i;
	int j;

	i = 0;
	while (i < tab->nb_y)
	{
		j = 0;
		while (j < tab->nb_x)
		{
			mlx_pixel_put(tab->mlx_ptr, tab->win_ptr, tab->p[i][j].x, tab->p[i][j].y, 0xFF003C);
			j++;	
		}
		i++;
	}
}

static void		init_map(t_tab *tab)
{
	float		i;
	float		j;
	float		x;
	float		y;

	i = 1;
	x = (tab->H * (i / (tab->nb_y + tab->z)));
	while (i < tab->nb_y + 1)
	{
		j = 1;
		while (j < tab->nb_x + 1)
		{
			tab->p[(int)i - 1][(int)j - 1].y = x + tab->y - (tab->h * tab->p[(int)i - 1][(int)j - 1].h);
			y = (tab->H * ((float)j / (tab->nb_x + tab->z))) + tab->x;
			tab->p[(int)i - 1][(int)j - 1].x = y + (i * 10 * tab->r);
			j++;
		}
		i++;
		x = (tab->L * ((float)i / (tab->nb_y + tab->z)));
	}
	line(tab);
	put_pixel(tab);
}

static int		event(int key, t_tab *tab)
{
	if (key == TOUCH_Q || key == TOUCH_ECHAP)
		exit(1);
	if (key == TOUCH_LEFT)
		tab->x -= 10;
	if (key == TOUCH_DOWN)
		tab->y += 10;
	if (key == TOUCH_RIGHT)
		tab->x += 10;
	if (key == TOUCH_UP)
		tab->y -= 10;
	if (key == TOUCH_NUMPAD_PLUS)
		tab->z--;
	if (key == TOUCH_NUMPAD_LESS)
		tab->z++;
	if (key == TOUCH_NUMPAD_2)
		tab->r++;
	if (key == TOUCH_NUMPAD_1)
		tab->r--;
	if (key == TOUCH_NUMPAD_5)
		tab->h++;
	if (key == TOUCH_NUMPAD_4)
		tab->h--;
	ft_printf("x = %d, y = %d, z = %d, h = %d, r = %d\n", tab->x, tab->y, tab->z, tab->h, tab->r);
	mlx_clear_window(tab->mlx_ptr, tab->win_ptr);
	init_map(tab);
	return (0);
}

void			aff(t_tab *tab)
{
	tab->z = 15;
	tab->r = 1;
	tab->h = 1;
	tab->L = 1700;
	tab->H = 1700;
	tab->x = tab->L / 2 - tab->L / tab->nb_x;
	tab->y = tab->H / 4 - tab->nb_y / tab->H;
	free_tab(tab);
	tab->mlx_ptr = mlx_init();
	tab->win_ptr = mlx_new_window(tab->mlx_ptr, tab->L, tab->H, "test");
	init_map(tab);
	mlx_key_hook(tab->win_ptr, event, tab);
	mlx_loop(tab->mlx_ptr);
}
