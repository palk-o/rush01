/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:55:50 by aperin            #+#    #+#             */
/*   Updated: 2022/09/18 13:57:37 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_colup(int **map, int col)
{
	int	i;
	int	j;
	int	view;

	i = 1;
	view = 1;
	while (i < 4)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (map[j][col] > map[i][col])
				break ;
			j--;
		}
		if (j == -1)
			view++;
		i++;
	}
	return (view);
}

int	get_coldown(int **map, int col)
{
	int	i;
	int	j;
	int	view;

	i = 2;
	view = 1;
	while (i >= 0)
	{
		j = i + 1;
		while (j < 4)
		{
			if (map[j][col] > map[i][col])
				break ;
			j++;
		}
		if (j == 4)
			view++;
		i--;
	}
	return (view);
}

int	get_row_left(int **map, int row)
{
	int	i;
	int	j;
	int	view;

	i = 1;
	view = 1;
	while (i < 4)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (map[row][j] > map[row][i])
				break ;
			j--;
		}
		if (j == -1)
			view++;
		i++;
	}
	return (view);
}

int	get_row_right(int **map, int row)
{
	int	i;
	int	j;
	int	view;

	i = 2;
	view = 1;
	while (i >= 0)
	{
		j = i + 1;
		while (j < 4)
		{
			if (map[row][j] > map[row][i])
				break ;
			j++;
		}
		if (j == 4)
			view++;
		i--;
	}
	return (view);
}
