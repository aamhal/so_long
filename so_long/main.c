/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:57:00 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 17:49:38 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int R_C_count(char *av, t_l *l)
{
    char *tmp;
    int fd;
    int i;

    fd = open(av, O_RDONLY, 0777);
    if (fd == -1)
        return (-1);
    tmp = get_next_line(fd);
    l->columns = ft_strlen(tmp) - 1;
    i = 0;
    while (tmp)
    {
        free(tmp);
        i++;
        tmp = get_next_line(fd);
    }
    l->rows = i;
    close (fd);
    return (0);
}



int check_extension(char *ber)
{
    char *p;
    int i;
    int j;
    
    p = ".ber";
    i = ft_strlen(ber) - 1;
    j = ft_strlen(p) - 1;

    while (i >= 0 && j >= 0)
    {
        if (ber[i] != p[j])
            return -1;
        i--;
        j--;
    }
    return (0);
}

int     check_sides(char *av, t_l *l)
{
    int fd;
    int i;

    i = 1;
	fd = open(av, O_RDONLY, 0777);
    if (fd == -1)
        return (-1);
    l->map = malloc((l->rows + 1) * sizeof(char *));
    if(!l->map)
    	return (-1);
	l->map[l->rows] = 0;
	l->map[0] = get_next_line(fd);
	if(!ft_first_w(l->map[0], l))
		return (-1);
	while (i < l->rows - 1)
	{
		l->map[i] = get_next_line(fd);
		if(!ft_sides(l->map[i], l))
			return (-1);
		i++;
	}
   l->map[i] = get_next_line(fd);
	if(!ft_last(l->map[i], l))
		return (-1);
	return (0);
}

int check_map(char **av, t_l *l)
{
    if (check_extension(av[1]) == -1)
        return (-1);
    R_C_count(av[1],l);
    if (check_sides(av[1],l) == -1)
        return (-1);
    if (check_char(l) == -1)
        return (-1);
    return(0);
}

int main(int ac, char **av)
{
    t_l l;
    t_mlx mlx;

    if (ac != 2)
        return (-1);
    if(check_map(av, &l) == -1)
        return(-1);
    mlx.map = &l;
    win_view(&l, &mlx);
    return (0);
}