/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:48:00 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/06 15:25:01 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j])
		{
			if (sl->map[i][j] == 'P')
				sl->p++;
			if (sl->map[i][j] == 'C')
				sl->c++;
			if (sl->map[i][j] == 'E')
				sl->e++;
		j++;
		}
	i++;
	}
	if (sl->p != 1 || sl->c == 0 || sl->e != 1)
		return (-1);
	return (0);
}
