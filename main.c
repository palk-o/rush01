/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:19:48 by aperin            #+#    #+#             */
/*   Updated: 2022/09/17 12:51:07 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	invalid_format(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (1);
	while (i < 31)
	{
		if (i % 2 == 1 && str[i] != ' ')
			return (1);
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (1);
		i++;
	}	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2 || invalid_format(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!solve_game(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (0);
}
