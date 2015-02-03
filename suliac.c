/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suliac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:35:38 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/03 16:12:10 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <time.h>
#include "puiss4.h"

void	clean_ret(int *ret)
{
	int		pow;
	int		i;

	for (i = 0; i < GRID_W; i++)
		if (ret[i] < 0)
		{
			pow = 1;
			while (!(ret[i] % 2))
			{
				ret[i] /= 10;
				pow *= 10;
			}
			ret [i] = (-1) * pow;
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
	int		best = 0;
	int		i;

	clean_ret(ret);
	for (i = 1; i < GRID_W; i++){
		if (ret[i] == 1)
			return (i);
		else if (ret[i] < ret[best])
			best = i;
		else if (ret[i] == ret[best] && get_bestindice(best, i))			
				best = i;
	}
	return (best);
}

int		main(){
	int	test[7] = {-1, -1000, -10000, -1, -100001000, -101000, -11000};

	printf("result : %d\n", drop_piece(test));
	return (0);
}
