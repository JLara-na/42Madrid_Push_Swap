/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:48:18 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/20 23:13:22 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reset(t_blist **a)
{
	t_blist	*head_a;
	int		size;

	head_a = (*a);
	size = ft_blstsize(*a);
	while (size--)
	{
		(*a)->cost = 0;
		(*a)->moves.ra = 0;
		(*a)->moves.rb = 0;
		(*a)->moves.rr = 0;
		(*a)->moves.rra = 0;
		(*a)->moves.rrb = 0;
		(*a)->moves.rrr = 0;
		(*a) = (*a)->next;
	}
	*a = head_a;
}

void	do_moves_pb(t_blist **a, t_blist **b, t_move moves)
{
	while (moves.rr-- > 0)
		rr_mov(a, b, PRINT);
	while (moves.rrr-- > 0)
		rrr_mov(a, b, PRINT);
	while (moves.ra-- > 0)
		ra_mov(a, PRINT);
	while (moves.rra-- > 0)
		rra_mov(a, PRINT);
	while (moves.rb-- > 0)
		rb_mov(b, PRINT);
	while (moves.rrb-- > 0)
		rrb_mov(b, PRINT);
	pb_mov(a, b, PRINT);
}

void	move_to_b(t_blist **a, t_blist **b, int index)
{
	t_blist	*aux;

	aux = *a;
	while (aux->index != index)
		aux = aux->next;
	do_moves_pb(a, b, aux->moves);
}

int	get_cheapest_index(t_blist *a)
{
	int	size;
	int	min;
	int	cheap_index;

	size = ft_blstsize(a);
	cheap_index = a->index;
	min = a->cost;
	while (size--)
	{
		if (a->cost < min)
		{
			min = a->cost;
			cheap_index = a->index;
		}
		a = a->next;
	}
	return (cheap_index);
}
