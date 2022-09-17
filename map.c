/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:54:51 by aperin            #+#    #+#             */
/*   Updated: 2022/09/17 13:16:01 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**init_map(void)
{
	int	**map;
	int	i;
	int	j;

	i = 0;
	map = (int**)malloc(4 * sizeof(int));
	if (map == 0)
		return (0);
	while (i < 4)
	{
		map[i] = (int*)malloc(4 * sizeof(int));
		if (map[i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (map);
}
