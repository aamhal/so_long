/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:28:25 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/23 21:54:47 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player(t_sl *sl)
{

	sl->py = 0;
	while (sl->map[sl->py])
	{
		sl->px = 0;
		while (sl->map[sl->py][sl->px])
		{
			if (sl->map[sl->py][sl->px] == 'P')
				return;
			sl->px++;
		}
		sl->py++;
	}
}

int key_hook(int key,t_sl *sl)
{
	find_player(sl);
	if (key == 53)
		ft_close(sl);
	else
		moves(key,sl);
	mlx_clear_window(sl->mlx, sl->win);
	put_img(sl);
	return (0);
}
