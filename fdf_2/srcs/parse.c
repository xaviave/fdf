/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 17:34:25 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 21:53:42 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_split(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			*fill_tab(char *split, t_mem *map, int size, int a)
{
	int		i;
	char	**split_space;
	int		*tab;

	i = 0;
	split_space = ft_strsplit(split, ' ');
	while (split_space[i])
		i++;
	map->nb_x = i;
	if (!(tab = (int *)malloc(sizeof(int) * i + 1)))
		return (NULL);
	i = 0;
	while (split_space[i])
	{
		tab[i] = ft_atoi(split_space[i]);
		if (a == 0 && i == 0)
		{
			map->min_z = tab[i];
			map->max_z = tab[i];
		}
		if (tab[i] < map->min_z)
			map->min_z = tab[i];
		else if (tab[i] > map->max_z)
			map->max_z = tab[i];
		i++;
	}
	map->nb_y = size;
	map->tab[size] = 0;
	free_split(split_space);
	return (tab);
}

void		parse2(t_mem *map, char **split, int i)
{
	int		a;
	
	a = 0;
	if (!(map->tab = (int **)malloc(sizeof(int *) * i + 1)))
		return ;
	while (a < i)
	{
		map->tab[a] = fill_tab(split[a], map, i, a);
		a++;
	}
	free_split(split);
	printf("%d      %d\n",  map->nb_y,  map->nb_x);
}

void		parse(t_mem *map, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	*tmp;
	char	**split;

	i = 0;
	fd = open(file, O_RDONLY);
	file = ft_strdup("");
	while (ft_gnl(fd, &line))
	{
		tmp = file;
		file = ft_strjoin(file, line);
		free(line);
		free(tmp);
		tmp = file;
		file = ft_strjoin(file, " |");
		free(tmp);
		i++;
	}
	close(fd);
	split = ft_strsplit(file, '|');
	free(file);
	parse2(map, split, i);
}