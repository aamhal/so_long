/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:48:00 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 17:33:00 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_char(t_l *l)
{
	int i;
	int j;

	i = 0;
	while (l->map[i])
	{
		j = 0;
		while (l->map[i][j])
		{
			if (l->map[i][j] == 'P')
				l->player++;
			if (l->map[i][j] == 'C')
				l->coins++;
			if (l->map[i][j] == 'E')
				l->exit++;
			j++;
		}
		i++;
	}
	if (l->player != 1)
		return (-1);
	if (l->coins == 0)
		return (-1);
	if (l->exit != 1)
		return (-1);
	return (0);
}