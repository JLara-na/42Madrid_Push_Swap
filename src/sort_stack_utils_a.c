/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:48:06 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/20 22:57:58 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_last_num(t_blist *s)
{
	while (s->next != NULL)
		s = (s)->next;
	return ((s)->num);
}

int	get_smoler_num(t_blist *s)
{
	int	smoler;

	smoler = s->num;
	while (s->next != NULL)
	{
		if (smoler > s->num)
			smoler = s->num;
		s = (s)->next;
	}
	return (smoler);
}

int	get_smoler_index(t_blist *s)
{
	int	smoler;
	int	smoler_index;
	int	size;

	smoler = s->num;
	smoler_index = s->index;
	size = ft_blstsize(s);
	while (size--)
	{
		if (smoler > s->num)
		{
			smoler = s->num;
			smoler_index = s->index;
		}
		s = (s)->next;
	}
	return (smoler_index);
}

int	get_bigger_num(t_blist *s)
{
	int	bigger;

	bigger = s->num;
	while (s->next != NULL)
	{
		if (bigger < s->num)
			bigger = s->num;
		s = (s)->next;
	}
	return (bigger);
}

void	do_moves_pa(t_blist **a, t_blist **b, t_move moves)
{
	while (moves.ra-- > 0)
		ra_mov(a, PRINT);
	while (moves.rra-- > 0)
		rra_mov(a, PRINT);
	pa_mov(a, b, PRINT);
}
