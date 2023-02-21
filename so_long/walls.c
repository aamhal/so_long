/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:32:04 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 11:36:31 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_first_w(char *line, t_l *l)
{
	int i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (i != l->columns)
		return (0);
	return (1);
}

int	ft_sides(char *line, t_l *l)
{
	int i;

	i = 0;
	if (line[i] != '1')
		return (0);
	
	while (line [i] != '\n')
	{
		if (!s_valid(line[i]))
			return (0);
		i++;
	}
	if (line[i - 1] != '1' || i != l->columns)
		return (0);
	return (1);
}

int	s_valid(char c)
{
	   if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
            return (1);
		return (0);
}

int	ft_last(char *line, t_l *l)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (i != l->columns)
		return (0);
	return (1);
}
