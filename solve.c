/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:41:27 by aperin            #+#    #+#             */
/*   Updated: 2022/09/18 14:03:14 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <stdio.h>

void	extract_input(char *input, int **view)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 31)
	{
		(*view)[j] = input[i] - 48;
		i += 2;
		j++;
	}
}

int	backtrack(int ***map, int *views, int *pos)
{
	if (pos[0] == -1 && pos[1] == -1)
	{
		if (solved(*map, views))
			return (1);
		else
			return (backtrack(map, views, prev_pos(pos)));
	}
	else if ((*map)[pos[0]][pos[1]] < 4)
	{
		(*map)[pos[0]][pos[1]] += 1;
		if (duplicate(*map, pos))
			return (backtrack(map, views, pos));
		return (backtrack(map, views, next_pos(pos)));
	}
	else if (!(pos[0] == 0 && pos[1] == 0))
	{
		(*map)[pos[0]][pos[1]] = 0;
		return (backtrack(map, views, prev_pos(pos)));
	}
	else
		return (0);
}

int	solve_game(char *input)
{
	int	**map;
	int	*views;
	int	start[2];

	map = build_map();
	views = malloc(16 * sizeof(int));
	if (views == 0)
		return (0);
	extract_input(input, &views);
	start[0] = 0;
	start[1] = 0;
	if (!backtrack(&map, views, start))
		return (0);
	print_map(map);
	free(map);
	free(views);
	return (1);
}
