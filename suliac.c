/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suliac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:35:38 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/03 15:11:51 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <time.h>

void	clean_ret(int *ret)
{
	int		pow;
	int		i;

	for (i = 0; i < GRID_W; i++)
		if (ret[i] < 0)
		{
			pow = 1;
			while (ret[i] / pow > 0)
				pow *= 10;
			ret [i] = pow;
		}
}

int		get_bestindice(int best, int i)
{
	best = GRID_W / 2 - best;
	i = GRID_W / 2 - i;

	best = (best >= 0) ? best : (-1) * best;
	i = (i >= 0) ? i : (-1) * i;

	if (best - i > 0)
		return (1);
	return (0);
}

int		drop_piece(int *ret)
{
	int		defeat = 0;
	int		i;

	clean_ret(ret);
	for (i = 1; i < GRID_W; i++){
		if (ret[i] == 1)
			return (i);
		if (ret[i] < ret[best])
			best = i;
		if (ret[i] == ret[best])
		{
			if (get_bestindice(best, i))			
				best = i;
		}
	}
	return (best);
}
