/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_getmove_sle_guil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:39:25 by jchichep          #+#    #+#             */
/*   Updated: 2015/02/03 16:39:09 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "puiss4.h"
#define DEEP 6

int		min(t_grid *grid, t_case color, int deep, t_case me);

int		remove_piece(t_grid *grid, int col)
{
	int		i;

	i = 0;
	while (i < GRID_H)
	{
		if ((*grid)[i][col] != VIDE)
		{
			(*grid)[i][col] = VIDE;
			return (1);
		}
		i++;
	}
	return (0); /* erreur */
}

int		play_piece(t_grid *grid, int col, t_case color)
{
	int		i;

	i = GRID_H;
	while (--i >= 0)
	{
		if ((*grid)[i][col] == VIDE)
		{
			(*grid)[i][col] = color;
			return (0);
		}
	}
	return (-1); /* erreur */
}

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
			if ((*grid)[i][j] == (*grid)[i][j + 1] && (*grid)[i][j + 1] == (*grid)[i][j + 2] && (*grid)[i][j + 2] == (*grid)[i][j + 3] && (*grid)[i][j] != VIDE)
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
			if ((*grid)[i][j] == (*grid)[i + 1][j] && (*grid)[i + 1][j] == (*grid)[i + 2][j] && (*grid)[i + 2][j] == (*grid)[i + 3][j] && (*grid)[i][j] != VIDE)
				return (1);
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}

int		is_winner_diagonal_left(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < GRID_H - 3)
	{
		while (j < GRID_W - 3)
		{
			if ((*grid)[i][j] == (*grid)[i + 1][j + 1] && (*grid)[i + 1][j + 1] == (*grid)[i + 2][j + 2] && (*grid)[i + 2][j + 2] == (*grid)[i + 3][j + 3] && (*grid)[i][j] != VIDE)
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
		while (j < GRID_W - 3)
		{
			if ((*grid)[i][j] == (*grid)[i - 1][j + 1] && (*grid)[i - 1][j + 1] == (*grid)[i - 2][j + 2] && (*grid)[i - 2][j + 2] == (*grid)[i - 3][j + 3] && (*grid)[i][j] != VIDE)
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

int		max_nb(int tab[GRID_W])
{
	int i;

	i = 0;
	while (i < GRID_W)
	{
		if (tab[i] == 0)
			return (0);
		++i;
	}
	return (-1);
}

int		max(t_grid *grid, t_case color, int deep)
{
	int tab[GRID_W] = { 0 };
	int i;
	t_case adv;

	i = 0;
	if (color == JAUNE)
		adv = ROUGE;
	else
		adv = JAUNE;
	if (deep < 0)
		return (0);
	while (i < GRID_W)
	{
		if (play_piece(grid, i + 1, color) != 0)
			tab[i] = 2;
		else
		{
			if (is_winner(grid) == 1)
			{
				remove_piece(grid, i + 1);
				return (1);
			}
			else
				remove_piece(grid, i + 1);
		}
		++i;
	}
	i = 0;
	while (i < GRID_W)
	{
		if (tab[i] != 2)
		{
			play_piece(grid, i + 1, color);
			tab[i] = min(grid, adv, deep - 1, color);
			remove_piece(grid, i + 1);
			if (tab[i] == 1)
				return (1);
		}
		++i;
	}
	return (max_nb(tab));
}

int		min_nb(int tab[GRID_W])
{
	int i;

	i = 0;
	while (i < GRID_W)
	{
		if (tab[i] == 0)
			return (0);
		++i;
	}
	return (1);
}

int		min(t_grid *grid, t_case color, int deep, t_case me)
{
	int tab[GRID_W] = { 0 };
	int i;

	i = 0;
	if (deep < 0)
		return (0);
	while (i < GRID_W)
	{
		if (play_piece(grid, i + 1, color) != 0)
			tab[i] = 2;
		else
		{
			if (is_winner(grid) == 1)
			{
				remove_piece(grid, i + 1);
				return (-1);
			}
			else
				remove_piece(grid, i + 1);
		}
		++i;
	}
	i = 0;
	while (i < GRID_W)
	{
		if (tab[i] != 2)
		{
			play_piece(grid, i + 1, color);
			tab[i] = max(grid, me, deep - 1);
			remove_piece(grid, i + 1);
			if (tab[i] == -1)
				return (-1);
		}
		++i;
	}
	return (min_nb(tab));
}

int		best_move(int tab[GRID_W])
{
	int i;
	int max;
	int tmp;

	max = -1;
	i = 0;
	while (i < GRID_W)
	{
		if (tab[i] == 1)
			return (i + 1);
		if (tab[i] == 0)
			max = 0;
		++i;
	}
	tmp = rand() % GRID_W;
	if (max == -1)
		return (rand() % GRID_W + 1);
	while (tab[tmp] != 0)
		tmp = rand() % GRID_W;
	return (tmp + 1);
}

int		move_to_play(t_grid *grid, t_case color, int deep)
{
	int tab[GRID_W] = { 0 };
	int i;
	t_case adv;

	if (color == JAUNE)
		adv = ROUGE;
	else
		adv = JAUNE;
	i = 0;
	while (i < GRID_W)
	{
		if (play_piece(grid, i + 1, color) != 0)
			tab[i] = 2;
		else
		{
			if (is_winner(grid) == 1)
			{
				remove_piece(grid, i + 1);
				return (i + 1);
			}
			else
				remove_piece(grid, i + 1);
		}
		++i;
	}
	i = 0;
	while (i < GRID_W)
	{
		if (tab[i] != 2)
		{
			play_piece(grid, i + 1, color);
			tab[i] = min(grid, adv, deep - 1, color);
			remove_piece(grid, i + 1);
			if (tab[i] == 1)
				return (i + 1);
		}
		i++;
	}
	return (best_move(tab));
}

int     p4_getmove_sle_guil(t_grid *grid, t_case color, int turn_count)
{
	int nb;

	if (41 - turn_count < DEEP)
		nb = move_to_play(grid, color, 41 - turn_count);
	else
		nb = move_to_play(grid, color, DEEP);
	return (nb);
}
