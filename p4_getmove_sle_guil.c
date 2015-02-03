/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_getmove_sle_guil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:39:25 by jchichep          #+#    #+#             */
/*   Updated: 2015/02/03 12:42:56 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"

int		is_winner_horizontal(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < GRID_H)
	{
		while (j < GRID_W - 3)
		{
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i][j + 3] && grid[i][j] != VIDE)
				return (1);
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}

int		is_winner_vertical(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < GRID_H - 3)
	{
		while (j < GRID_W)
		{
			if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j] && grid[i + 2][j] == grid[i + 3][j] && grid[i][j] != VIDE)
				return (1);
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}

int		is_winner_diagaonal_left(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < GRID_H - 3)
	{
		while (j < GRID_W - 3)
		{
			if (grid[i][j] == grid[i + 1][j + 1] && grid[i + 1][j + 1] == grid[i + 2][j + 2] && grid[i + 2][j + 2] == grid[i + 3][j + 3] && grid[i][j] != VIDE)
				return (1);
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}

int		is_winner_diagonal_right(t_grid *grid)
{
	int i;
	int j;

	i = 3;
	j = 0;
	while (i < GRID_H)
	{
		while (j < GRID_W < 3)
		{
			if (grid[i][j] == grid[i - 1][j + 1] && grid[i - 1][j + 1] == grid[i - 2][j + 2] && grid[i - 2][j + 2] == grid[i - 3][j + 3] && grid[i][j] != VIDE)
				return (1);
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}

int		is_winner(t_grid *grid)
{
	int ret;

	ret = 0;
	ret += is_winner_horizontal(grid);
	ret += is_winner_vertical(grid);
	ret += is_winner_diagonal_left(grid);
	ret += is_winner_diagonal_right(grid);
	if (ret == 0)
		return (0);
	return (1);
}

int     p4_getmove_sle_guil(t_grid *grid, t_case color, int turn_count)
{
	int nb;

	return (nb);
}
