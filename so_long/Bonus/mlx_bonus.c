/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:04:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/07 17:20:05 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_monster(t_sl *sl)
{
	sl->sky = mlx_xpm_file_to_image(sl->mlx, "textures/sky.xpm", \
	&sl->weight, &sl->hight);
	sl->monster = mlx_xpm_file_to_image(sl->mlx, "textures/monster.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->sky ||!sl->monster)
		ft_error();
	mlx_put_image_to_window(sl->mlx, sl->win, sl->sky, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->monster, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_destroy_image(sl->mlx, sl->sky);
	mlx_destroy_image(sl->mlx, sl->monster);
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
			if (sl->map[sl->y][sl->x] == 'M')
				put_monster(sl);
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
	sl->moves = 0;
	mlx_hook(sl->win, 2, 0, key_hook, sl);
	mlx_hook(sl->win, 17, 0, ft_close, sl);
	mlx_string_put(sl->mlx, sl->win, 32, \
	sl->rows * SIZE + 16, 0xffffff, "0");
	mlx_loop(sl->mlx);
	return (0);
}

int	ft_close(t_sl *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit(1);
	return (0);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
