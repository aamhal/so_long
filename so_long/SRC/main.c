/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:57:00 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/25 13:35:16 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int R_C_count(char *av, t_sl *sl)
{
    char *tmp;
    int fd;
    int i;

    fd = open(av, O_RDONLY, 0777);
    if (fd == -1)
        return (-1);
    tmp = get_next_line(fd);
    sl->columns = ft_strlen(tmp) - 1;
    i = 0;
    while (tmp)
    {
        free(tmp);
        i++;
        tmp = get_next_line(fd);
    }
    sl->rows = i;
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

int     check_sides(char *av, t_sl *sl)
{
    int fd;
    int i;

    i = 1;
	fd = open(av, O_RDONLY, 0777);
    if (fd == -1)
        return (-1);
    sl->map = malloc((sl->rows + 1) * sizeof(char *));
    if(!sl->map)
    	return (-1);
	sl->map[sl->rows] = 0;
	sl->map[0] = get_next_line(fd);
	if(!ft_first_w(sl->map[0], sl))
		return (-1);
	while (i < sl->rows - 1)
	{
		sl->map[i] = get_next_line(fd);
		if(!ft_sides(sl->map[i], sl))
			return (-1);
		i++;
	}
   sl->map[i] = get_next_line(fd);
	if(!ft_last(sl->map[i], sl))
		return (-1);
	return (0);
}

int check_map(char **av, t_sl *sl)
{
    if (check_extension(av[1]) == -1)
        return (-1);
    R_C_count(av[1],sl);
    if (check_sides(av[1],sl) == -1)
        return (-1);
    if (check_char(sl) == -1)
        return (-1);
    if(valid_path(av[1],sl) == -1)
        return (-1);
    return(0);
}

int main(int ac, char **av)
{
    t_sl sl;

    if (ac != 2)
        return (-1);
    if(check_map(av, &sl) == -1)
        return(ft_printf("map invalid!!!!"),-1);
    win_view(&sl);
    return (0);
}