/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:48:21 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/20 23:12:18 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	join_moves(t_blist **a, t_blist **b)
{
	int	rb;
	int	rrb;

	rb = (*b)->moves.rb;
	rrb = (*b)->moves.rrb;
	while ((*a)->moves.ra > 0 && rb > 0)
	{
		(*a)->moves.ra--;
		rb--;
		(*a)->moves.rr++;
	}
	while ((*a)->moves.rra > 0 && rrb > 0)
	{
		(*a)->moves.rra--;
		rrb--;
		(*a)->moves.rrr++;
	}
	(*a)->moves.rb = rb;
	(*a)->moves.rrb = rrb;
	(*a)->cost = ((*a)->moves.ra + (*a)->moves.rb + (*a)->moves.rr
			+ (*a)->moves.rra + (*a)->moves.rrb + (*a)->moves.rrr);
}

void	check_cost_a_to_b(t_blist **a, t_blist **b, int index)
{
	t_blist	*head_b;
	int		i;

	head_b = *b;
	i = 0;
	while ((*b)->index != index)
		*b = (*b)->next;
	join_moves(a, b);
	*b = head_b;
}

int	check_index_a_to_b(t_blist **stack_a, t_blist **stack_b, int size)
{
	int	max;
	int	max_index;
	int	b_head;

	max = (*stack_b)->num;
	b_head = (*stack_b)->num;
	*stack_b = (*stack_b)->next;
	while (size-- > 1)
	{
		if ((*stack_b)->num > max)
		{
			max = (*stack_b)->num;
			max_index = (*stack_b)->index;
		}
		if ((*stack_a)->num > (*stack_b)->num
			&& (*stack_a)->num < (*stack_b)->prev->num)
			return ((*stack_b)->index);
		if ((*stack_a)->num > (*stack_b)->num
			&& (*stack_b)->num > (*stack_b)->prev->num)
			return ((*stack_b)->index);
		*stack_b = (*stack_b)->next;
	}
	if (max > b_head && (*stack_a)->num < b_head)
		return (max_index);
	return (0);
}

void	get_moves_a_to_b(t_blist **a, t_blist **b)
{
	t_blist	*head_a;
	t_blist	*head_b;
	int		i;
	int		b_index;

	head_a = *a;
	head_b = *b;
	i = ft_blstsize(*a);
	while (i--)
	{
		b_index = check_index_a_to_b(a, b, ft_blstsize(*b));
		*b = head_b;
		check_cost_a_to_b(a, b, b_index);
		*a = (*a)->next;
	}
	*a = head_a;
}

void	get_moves_b(t_blist **b)
{
	t_blist	*head_b;
	int		b_size;
	int		b_count;

	head_b = *b;
	b_size = ft_blstsize(*b);
	b_count = b_size;
	while (b_count--)
	{
		if ((*b)->index <= b_size / 2)
		{
			(*b)->moves.rb = ((*b)->index);
			(*b)->moves.rrb = 0;
		}
		else
		{
			(*b)->moves.rrb = (b_size - (*b)->index);
			(*b)->moves.rb = 0;
		}
		(*b) = (*b)->next;
	}
	(*b) = head_b;
}
