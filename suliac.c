/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suliac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:35:38 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/03 11:51:58 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <time.h>

int		drop_piece(t_grid *grid, int col, int ligne)
{
	if ((*grid)[col][ligne] == VIDE)
		return (1);
	return (0);
}
