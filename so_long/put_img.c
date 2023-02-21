/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:32:40 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 17:33:50 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_player(t_mlx *mlx)
{
	mlx->player = mlx_xpm_file_to_image(mlx->mlx,"img/player.xpm", &mlx->weight,&mlx->hight);
	mlx_put_image_to_window(mlx->mlx,mlx->win,mlx->player,mlx->x * SIZE,mlx->y * SIZE);
	mlx_destroy_image(mlx->mlx, mlx->player);
}
void put_coin(t_mlx *mlx)
{
	mlx->coin = mlx_xpm_file_to_image(mlx->mlx,"img/coin.xpm", &mlx->weight,&mlx->hight);
	mlx_put_image_to_window(mlx->mlx,mlx->win,mlx->coin,mlx->x * SIZE,mlx->y * SIZE);
	mlx_destroy_image(mlx->mlx, mlx->coin);
}
void put_exit(t_mlx *mlx)
{
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx,"img/exit.xpm", &mlx->weight,&mlx->hight);
	mlx_put_image_to_window(mlx->mlx,mlx->win,mlx->exit,mlx->x * SIZE,mlx->y * SIZE);
	mlx_destroy_image(mlx->mlx, mlx->exit);
}
void put_wall(t_mlx *mlx)
{
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx,"img/wall.xpm", &mlx->weight,&mlx->hight);
	mlx_put_image_to_window(mlx->mlx,mlx->win,mlx->wall,mlx->x * SIZE,mlx->y * SIZE);
	mlx_destroy_image(mlx->mlx, mlx->wall);
}
void put_sky(t_mlx *mlx)
{
	mlx->sky = mlx_xpm_file_to_image(mlx->mlx,"img/sky.xpm", &mlx->weight,&mlx->hight);
	mlx_put_image_to_window(mlx->mlx,mlx->win,mlx->sky,mlx->x * SIZE,mlx->y * SIZE);
	mlx_destroy_image(mlx->mlx, mlx->sky);
}