/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:41:27 by aperin            #+#    #+#             */
/*   Updated: 2022/09/17 14:34:30 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <stdio.h>

void	print_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

void	extract_input(char *input, int **rule)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 31)
	{
		(*rule)[j] = input[i] - 48;
		i += 2;
		j++;
	}
}

int	solve(char *input)
{
	int	**map;
	int	*rule;

	map = build_map();
	rule = malloc(16 * sizeof(int));
	if (rule == 0)
		return (0);
	extract_input(input, &rule);
	print_map(map);
	print_tab(rule);
	return (1);
}
