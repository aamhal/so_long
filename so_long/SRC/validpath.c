/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:49:10 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/06 13:55:01 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_map(char *av, t_sl *sl)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(av, O_RDONLY, 0777);
	if (fd == -1)
		return (-1);
	sl->vpm = malloc((sl->rows + 1) * sizeof(char *));
	if (!sl->vpm)
		return (-1);
	sl->vpm[sl->rows] = 0;
	while (i < sl->rows)
	{
		sl->vpm[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

void	put_p(t_sl *sl, int r, int c, int *f)
{
	if (sl->vpm[r][c + 1] == '0' || sl->vpm[r][c + 1] == 'C')
	{
		*f = 1;
		sl->vpm[r][c + 1] = 'P' ;
	}
	if (sl->vpm[r][c - 1] == '0' || sl->vpm[r][c - 1] == 'C')
	{
		*f = 1;
		sl->vpm[r][c - 1] = 'P' ;
	}
	if (sl->vpm[r + 1][c] == '0' || sl->vpm[r + 1][c] == 'C')
	{
		*f = 1;
		sl->vpm[r + 1][c] = 'P' ;
	}
	if (sl->vpm[r - 1][c] == '0' || sl->vpm[r - 1][c] == 'C')
	{
		*f = 1;
		sl->vpm[r - 1][c] = 'P' ;
	}
}

void	fill_map(t_sl *sl)
{
	int	x;
	int	y;
	int	f;

	y = 0;
	f = 0;
	while (sl->vpm[y])
	{
		x = 0;
		while (sl->vpm[y][x])
		{
			if (sl->vpm[y][x] == 'P')
				put_p(sl, y, x, &f);
			x++;
		}
		y++;
	}
	if (f)
		fill_map(sl);
}

int	ft_mcheck(char **p)
{
	int	y;
	int	x;
	int	c;

	c = 0;
	y = 0;
	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{
			if (p[y][x] == 'C')
			{
				c++;
			}
			x++;
		}
		y++;
	}
	if (c != 0)
		return (-1);
	if (ft_echeck(p) == -1)
		return (-1);
	return (0);
}

int	valid_path(char *av, t_sl *sl)
{
	new_map(av, sl);
	fill_map(sl);
	if (ft_mcheck(sl->vpm) == -1)
	{
		ft_free(sl->vpm, sl->rows);
		return (-1);
	}
	else
		ft_free(sl->vpm, sl->rows);
	return (0);
}
