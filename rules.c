/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:57:57 by aperin            #+#    #+#             */
/*   Updated: 2022/09/18 13:59:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>

int	duplicate(int **map, int *pos)
{
	int	i;

	i = 0;
	while (i < pos[0])
	{
		if (map[i][pos[1]] == map[pos[0]][pos[1]])
			return (1);
		i++;
	}
	i = 0;
	while (i < pos[1])
	{
		if (map[pos[0]][i] == map[pos[0]][pos[1]])
			return (1);
		i++;
	}
	return (0);
}

int	*get_views(int **map, int **curr_views)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*curr_views)[i] = get_colup(map, i);
		(*curr_views)[i + 4] = get_coldown(map, i);
		(*curr_views)[i + 8] = get_row_left(map, i);
		(*curr_views)[i + 12] = get_row_right(map, i);
		i++;
	}
	return (*curr_views);
}

int	solved(int **map, int *views)
{
	int	*curr_views;
	int	i;

	curr_views = malloc(16 * sizeof(int));
	if (curr_views == 0)
		return (0);
	curr_views = get_views(map, &curr_views);
	i = 0;
	while (i < 16 && curr_views[i] == views[i])
		i++;
	free(curr_views);
	if (i == 16)
		return (1);
	return (0);
}
