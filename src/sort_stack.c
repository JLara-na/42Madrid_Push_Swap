/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:06:55 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/20 23:10:47 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_to_a(t_blist	**a, t_blist **b, int index)
{
	t_blist	*aux;

	aux = *a;
	while (aux->index != index)
		aux = aux->next;
	do_moves_pa(a, b, aux->moves);
}

int	check_index_b_to_a(t_blist *a, t_blist *b, int size)
{
	int	max;
	int	min_index;

	max = a->num;
	min_index = get_smoler_index(a);
	a = (a)->next;
	while (size-- > 1)
	{
		if ((a)->num > max)
			max = (a)->num;
		if ((b)->num < (a)->num && (b)->num > (a)->prev->num)
			return ((a)->index);
		if ((b)->num < (a)->num && (a)->num < (a)->prev->num)
			return ((a)->index);
		a = (a)->next;
	}
	if (b->num == get_bigger_num(b) && get_bigger_num(b) > max)
		return (min_index);
	return (0);
}

void	going_a(t_blist **a, t_blist **b)
{
	int	size;
	int	index;

	size = ft_blstsize(*b);
	reset(a);
	reset(b);
	while (size--)
	{
		reset(a);
		reset(b);
		get_moves_a(a);
		index = check_index_b_to_a(*a, *b, ft_blstsize(*a));
		move_to_a(a, b, index);
	}
}

void	sort_more(t_blist	**a, t_blist	**b)
{
	int	cheapest_index;

	pb_mov(a, b, PRINT);
	pb_mov(a, b, PRINT);
	while (ft_blstsize(*a) > 3)
	{
		cheapest_index = get_cheapest_a_to_b(a, b);
		move_to_b(a, b, cheapest_index);
		reset(a);
	}
	if (!is_it_ordered(*a))
		sort_three(a);
	going_a(a, b);
	order(a);
}

void	sort_stack(t_blist **stack_a, t_blist **stack_b, int size)
{
	if (size == 2)
		sa_mov(stack_a, 1);
	if (size == 3)
		sort_three(stack_a);
	if (size == 5 || size == 4)
		sort_four_five(stack_a, stack_b, size);
	if (size > 5)
		sort_more(stack_a, stack_b);
}
