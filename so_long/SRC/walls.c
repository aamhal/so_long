/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:32:04 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/02 16:11:53 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_first_w(char *line, t_sl *sl)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (i != sl->columns)
		return (0);
	return (1);
}

int	ft_sides(char *line, t_sl *sl)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	while (line[i] != '\n')
	{
		if (!s_valid(line[i]))
			return (0);
		i++;
	}
	if (line[i - 1] != '1' || i != sl->columns)
	{
		return (0);
	}
	return (1);
}

int	s_valid(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

int	ft_last(char *line, t_sl *sl)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (i != sl->columns)
		return (0);
	return (1);
}

int	ft_echeck(char **p)
{
	int	y;
	int	x;

	y = 0;
	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{
			if (p[y][x] == 'E')
			{
				if (p[y][x + 1] == 'P' || p[y][x - 1] == 'P' || \
				p[y - 1][x] == 'P' || p[y + 1][x] == 'P')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}
