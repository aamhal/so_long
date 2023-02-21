/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:04:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 17:50:20 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_img(t_l *l, t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;

	while (l->map[mlx->y])
	{
		mlx->x = 0;
		while (l->map[mlx->y][mlx->x])
		{
			if (l->map[mlx->y][mlx->x] == 'P')
				put_player(mlx);
			if (l->map[mlx->y][mlx->x] == 'C')
				put_coin(mlx);
			if (l->map[mlx->y][mlx->x] == 'E')
				put_exit(mlx);
			if (l->map[mlx->y][mlx->x] == '0')
				put_sky(mlx);
			if (l->map[mlx->y][mlx->x] == '1')
				put_wall(mlx);
			mlx->x++;
		}
		mlx->y++;
	}
}

int win_view(t_l *l,t_mlx *mlx)
{	
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx,l->columns * 64,l->rows * 64,"so_long");
	
	put_img(l,mlx);
	mlx_hook(mlx->win, 2, 0, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, ft_close, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

int ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx,mlx->win);
	exit(1);
	return (0);
}