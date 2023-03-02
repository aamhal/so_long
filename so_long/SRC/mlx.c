/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:04:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/26 13:25:23 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	des_img(t_sl *sl)
{
	mlx_destroy_image(sl->mlx, sl->player);
	mlx_destroy_image(sl->mlx, sl->sky);
	mlx_destroy_image(sl->mlx, sl->coin);
	mlx_destroy_image(sl->mlx, sl->exit);
	mlx_destroy_image(sl->mlx, sl->wall);
}

void	put_img(t_sl *sl)
{
	sl->x = 0;
	sl->y = 0;
	while (sl->map[sl->y])
	{
		sl->x = 0;
		while (sl->map[sl->y][sl->x])
		{
			if (sl->map[sl->y][sl->x] == 'P')
				put_player(sl);
			if (sl->map[sl->y][sl->x] == 'C')
				put_coin(sl);
			if (sl->map[sl->y][sl->x] == 'E')
				put_exit(sl);
			if (sl->map[sl->y][sl->x] == '0')
				put_sky(sl);
			if (sl->map[sl->y][sl->x] == '1')
				put_wall(sl);
			sl->x++;
		}
		sl->y++;
	}
}

int	ft_close(t_sl *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit(1);
	return (0);
}

int	win_view(t_sl *sl)
{	
	sl->mlx = mlx_init();
	sl->win = mlx_new_window(sl->mlx, sl->columns * 64, \
	sl->rows * SIZE, "so_long");
	put_img(sl);
	sl->moves = 1;
	mlx_hook(sl->win, 2, 0, key_hook, sl);
	mlx_hook(sl->win, 17, 0, ft_close, sl);
	des_img(sl);
	mlx_loop(sl->mlx);
	return (0);
}
