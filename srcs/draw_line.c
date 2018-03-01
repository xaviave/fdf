/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 10:40:00 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 13:35:30 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_line(t_line *line)
{
	line->sx = (line->x1 < line->x2 ? 1 : -1);
	line->sy = (line->y1 < line->y2 ? 1 : -1);
	line->dx = ft_abs(line->x2 - line->x1);
	line->dy = ft_abs(line->y2 - line->y1);
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
}
/*
static int	change_color(int h, int nb_p, int p)
{
	int		i;
	int		color;

	i = 0;
	color = 0x00FF5D;
	if (h == 0)
		return (color);
	else
	{
		while (i < h)
		{
			color = 0x00FF5D + i;
			i += nb_p / p;
		}
	}
	ft_printf("color = %d\n", color);
	return (color);
}
*/
static int	count_line(t_tab *tab, t_line *line)
{
	int		e2;
	int		i;

	i = 0;
	init_line(line);
	while (1)
	{
		i++;
		if (line->x1 == line->x2 && line->y1 == line->y2)
			break ;
		e2 = line->err;
		if (e2 > -line->dx)
		{
			line->err -= line->dy;
			line->x1 += line->sx;
		}
		if (e2 < line->dy)
		{
			line->err += line->dx;
			line->y1 += line->sy;
		}
	}
	return (i);
}

static void	put_line(t_tab *tab, t_line *line)
{
	int		e2;
	int		i;
	int		j;

	j = 0;
	init_line(line);
//	i = count_line(tab, line);
	while (1)
	{
		mlx_pixel_put(tab->mlx_ptr, tab->win_ptr, line->x1, line->y1, 0x0000FF);
		if (line->x1 == line->x2 && line->y1 == line->y2)
			break ;
		e2 = line->err;
		if (e2 > -line->dx)
		{
			line->err -= line->dy;
			line->x1 += line->sx;
		}
		if (e2 < line->dy)
		{
			line->err += line->dx;
			line->y1 += line->sy;
		}
		j++;
	}
}

int			line2(t_tab *tab, t_line *line)
{
	int		i;
	int		j;

	i = 0;
	while (i < tab->nb_y)
	{
		j = 0;
		while (j < tab->nb_x - 1)
		{
			line->x1 = tab->p[i][j].x;
			line->y1 = tab->p[i][j].y;
			line->x2 = tab->p[i][j + 1].x;
			line->y2 = tab->p[i][j + 1].y;
			put_line(tab, line);
			j++;
		}
		i++;
	}
	return (1);
}

int			line(t_tab *tab)
{
	int		i;
	int		j;
	t_line	*line;

	i = 0;
	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (0);
	while (i < tab->nb_y - 1)
	{
		j = 0;
		while (j < tab->nb_x - 1)
		{
			line->x1 = tab->p[i][j].x;
			line->y1 = tab->p[i][j].y;
			line->x2 = tab->p[i + 1][j].x;
			line->y2 = tab->p[i + 1][j].y;
			put_line(tab, line);
			j++;
		}
		line->x1 = tab->p[i][j].x;
		if (tab->p[i][j].h == 0)
			line->y1 = tab->p[i][j].y;
		line->x2 = tab->p[i + 1][j].x;
		if (tab->p[i][j].h == 0)
			line->y2 = tab->p[i + 1][j].y;
		put_line(tab, line);
		i++;
	}
	return (line2(tab, line));
}
