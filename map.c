/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:54:51 by aperin            #+#    #+#             */
/*   Updated: 2022/09/18 13:51:57 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*next_pos(int *pos)
{
	if (pos[1] < 3)
		pos[1]++;
	else if (pos[0] < 3)
	{
		pos[0]++;
		pos[1] = 0;
	}
	else
	{
		pos[0] = -1;
		pos[1] = -1;
	}
	return (pos);
}

int	*prev_pos(int *pos)
{
	if (pos[0] == -1 && pos[1] == -1)
	{
		pos[0] = 3;
		pos[1] = 3;
	}
	if (pos[1] > 0)
		pos[1]--;
	else
	{
		pos[0]--;
		pos[1] = 3;
	}
	return (pos);
}

void	init_map(int ***map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*map)[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**build_map(void)
{
	int	**map;
	int	i;

	i = 0;
	map = (int **)malloc(4 * sizeof(int *));
	if (map == 0)
		return (0);
	while (i < 4)
	{
		map[i] = (int *)malloc(4 * sizeof(int));
		if (map[i] == 0)
			return (0);
		i++;
	}
	init_map(&map);
	return (map);
}

void	print_map(int **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = map[i][j] + 48;
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
