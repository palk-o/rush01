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

int		solve_game(char *input);

int		*next_pos(int *pos);
int		*prev_pos(int *pos);
int	    **build_map(void);
void	print_map(int **map);

int		duplicate(int **map, int *pos);
int		solved(int **map, int *rules);

int get_colup(int **map, int col);
int get_coldown(int **map, int col);
int get_row_left(int **map, int row);
int get_row_right(int **map, int row);

#endif
