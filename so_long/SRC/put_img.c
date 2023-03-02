/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:32:40 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/02 14:56:28 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_sl *sl)
{
	sl->player = mlx_xpm_file_to_image(sl->mlx, "img/player.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->player)
	{
		ft_free(sl->map);
		exit(1);
	}
	mlx_put_image_to_window(sl->mlx, sl->win, sl->player, \
	sl->x * SIZE, sl->y * SIZE);
}

void	put_sky(t_sl *sl)
{
	sl->sky = mlx_xpm_file_to_image(sl->mlx, "img/sky.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->sky)
	{
		ft_free(sl->map);
		exit(1);
	}
	mlx_put_image_to_window(sl->mlx, sl->win, sl->sky, \
	sl->x * SIZE, sl->y * SIZE);
}

void	put_coin(t_sl *sl)
{
	sl->sky = mlx_xpm_file_to_image(sl->mlx, "img/sky.xpm", \
	&sl->weight, &sl->hight);
	sl->coin = mlx_xpm_file_to_image(sl->mlx, "img/coin1.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->sky ||!sl->coin)
	{
		ft_free(sl->map);
		exit(1);
	}
	mlx_put_image_to_window(sl->mlx, sl->win, sl->sky, \
	sl->x * SIZE, sl->y * SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->coin, \
	sl->x * SIZE, sl->y * SIZE);
}

void	put_exit(t_sl *sl)
{
	sl->exit = mlx_xpm_file_to_image(sl->mlx, "img/cexit.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->exit)
	{
		ft_free(sl->map);
		exit(1);
	}
	mlx_put_image_to_window(sl->mlx, sl->win, sl->exit, \
	sl->x * SIZE, sl->y * SIZE);
}

void	put_wall(t_sl *sl)
{
	sl->wall = mlx_xpm_file_to_image(sl->mlx, "img/wall.xpm", \
	&sl->weight, &sl->hight);
	if (!sl->wall)
	{
		ft_free(sl->map);
		exit(1);
	}
	mlx_put_image_to_window(sl->mlx, sl->win, sl->wall, \
	sl->x * SIZE, sl->y * SIZE);
}
