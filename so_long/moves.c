/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:04 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 17:33:44 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int moves(int key, t_l *l)
{
	if (key == 124)
		{
			l->map[l->y][l->x] = '0';
			l->x += 1;
			l->map[l->y][l->x] = 'P';
		}
	return (0);
}