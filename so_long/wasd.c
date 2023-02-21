/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:28:25 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 17:51:00 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player(t_l *l)
{

	l->y = 0;
	while (l->map[l->y])
	{
		l->x = 0;
		while (l->map[l->y][l->x])
		{
			if (l->map[l->y][l->x] == 'P')
				return;
			l->x++;
		}
		l->y++;
		// printf("%d\n",l->x);
		// printf("%d\n",l->y);
	}
}

int key_hook(int key,t_mlx *mlx)
{
	find_player(mlx->map);
	if (key == 53)
		ft_close(mlx);
	else
		moves(key,mlx->map);
	mlx_clear_window(mlx->mlx, mlx->win);
	put_img(mlx->map,mlx);
	return (0);
}
