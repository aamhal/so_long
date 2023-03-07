/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:32:40 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/06 21:04:57 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player(t_sl *sl)
{
	if (sl->ppos == 1)
	{
		sl->player = mlx_xpm_file_to_image(sl->mlx, "textures/player.xpm", \
		&sl->weight, &sl->hight);
		if (!sl->player)
			ft_error();
		mlx_put_image_to_window(sl->mlx, sl->win, sl->player, \
		sl->x * SIZE, sl->y * SIZE);
		mlx_destroy_image(sl->mlx, sl->player);
	}
	else
	{
		sl->player = mlx_xpm_file_to_image(sl->mlx, "textures/lplayer.xpm", \
		&sl->weight, &sl->hight);
		if (!sl->player)
			ft_error();
		mlx_put_image_to_window(sl->mlx, sl->win, sl->player, \
		sl->x * SIZE, sl->y * SIZE);
		mlx_destroy_image(sl->mlx, sl->player);
	}
}

void	put_sky(t_sl *sl)
{
	sl->sky = mlx_xpm_file_to_image(sl->mlx, "textures/sky.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->sky)
		ft_error();
	mlx_put_image_to_window(sl->mlx, sl->win, sl->sky, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_destroy_image(sl->mlx, sl->sky);
}

void	put_coin(t_sl *sl)
{
	sl->sky = mlx_xpm_file_to_image(sl->mlx, "textures/sky.xpm", \
	&sl->weight, &sl->hight);
	sl->coin = mlx_xpm_file_to_image(sl->mlx, "textures/coin1.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->sky || !sl->coin)
		ft_error();
	mlx_put_image_to_window(sl->mlx, sl->win, sl->sky, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->coin, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_destroy_image(sl->mlx, sl->sky);
	mlx_destroy_image(sl->mlx, sl->coin);
}

void	put_exit(t_sl *sl)
{
	if (sl->c > 0)
	{
		sl->exit = mlx_xpm_file_to_image(sl->mlx, "textures/cexit.xpm", \
		&sl->weight, &sl->hight);
		if (!sl->exit)
			ft_error();
		mlx_put_image_to_window(sl->mlx, sl->win, sl->exit, \
		sl->x * SIZE, sl->y * SIZE);
		mlx_destroy_image(sl->mlx, sl->exit);
	}
	else
	{
		sl->exit = mlx_xpm_file_to_image(sl->mlx, "textures/oexit.xpm", \
		&sl->weight, &sl->hight);
		if (!sl->exit)
			ft_error();
		mlx_put_image_to_window(sl->mlx, sl->win, sl->exit, \
		sl->x * SIZE, sl->y * SIZE);
		mlx_destroy_image(sl->mlx, sl->exit);
	}
}

void	put_wall(t_sl *sl)
{
	sl->wall = mlx_xpm_file_to_image(sl->mlx, "textures/wall.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->wall)
		ft_error();
	mlx_put_image_to_window(sl->mlx, sl->win, sl->wall, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_destroy_image(sl->mlx, sl->wall);
}
