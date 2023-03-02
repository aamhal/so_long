/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:04:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/25 15:50:40 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	des_img(t_sl *sl)
{
	mlx_destroy_image(sl->mlx, sl->player);
	mlx_destroy_image(sl->mlx, sl->sky);
	mlx_destroy_image(sl->mlx, sl->coin);
	mlx_destroy_image(sl->mlx, sl->exit);
	mlx_destroy_image(sl->mlx, sl->wall);
}

void	put_monster(t_sl *sl)
{
	sl->monster = mlx_xpm_file_to_image(sl->mlx, "img/monster.xpm", \
	&sl->weight, &sl->hight);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->sky, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->monster, \
	sl->x * SIZE, sl->y * SIZE);
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
			if (sl->map[sl->y][sl->x] == 'M')
				put_monster(sl);
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

int	win_view(t_sl *sl)
{	
	sl->mlx = mlx_init();
	sl->win = mlx_new_window(sl->mlx, sl->columns * 64, \
	sl->rows * SIZE + SIZE, "so_long");
	put_img(sl);
	mlx_hook(sl->win, 2, 0, key_hook, sl);
	mlx_hook(sl->win, 17, 0, ft_close, sl);
	mlx_string_put(sl->mlx, sl->win, 32, \
	sl->rows * SIZE + 16, 0xffffff, "0");
	des_img(sl);
	mlx_loop(sl->mlx);
	return (0);
}

int	ft_close(t_sl *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit(1);
	return (0);
}
