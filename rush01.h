/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:47:30 by aperin            #+#    #+#             */
/*   Updated: 2022/09/17 13:05:12 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01
#define RUSH01

int		ft_strlen(char *str);
void	ft_putstr(char *str);

int		solve(char *input);

int	    **build_map(void);
void	print_map(int **map);

#endif
