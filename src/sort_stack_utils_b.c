/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:48:13 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/20 23:12:46 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_moves_a(t_blist **a)
{
	t_blist	*head_a;
	int		a_size;
	int		a_count;

	head_a = *a;
	a_size = ft_blstsize(*a);
	a_count = a_size;
	while (a_count--)
	{
		if ((*a)->index <= a_size / 2)
		{
			(*a)->moves.ra = ((*a)->index);
			(*a)->moves.rra = 0;
		}
		else
		{
			(*a)->moves.rra = (a_size - (*a)->index);
			(*a)->moves.ra = 0;
		}
		(*a) = (*a)->next;
	}
	(*a) = head_a;
}

int	get_cheapest_a_to_b(t_blist **a, t_blist **b)
{
	get_moves_a(a);
	get_moves_b(b);
	get_moves_a_to_b(a, b);
	return (get_cheapest_index(*a));
}

int	is_max_first(t_blist **stack)
{
	t_blist	*aux;
	int		size;
	int		max;
	int		max_index;

	aux = (*stack);
	max = aux->num;
	max_index = aux->index;
	size = ft_blstsize(*stack);
	while (size--)
	{
		if (max < aux->num)
		{
			max = aux->num;
			max_index = aux->index;
		}
		aux = aux->next;
	}
	size = ft_blstsize(*stack);
	return (max_index == 0);
}

int	is_max_above(t_blist **stack)
{
	t_blist	*aux;
	int		size;
	int		max;
	int		max_index;

	aux = (*stack);
	max = aux->num;
	max_index = aux->index;
	size = ft_blstsize(*stack);
	while (size--)
	{
		if (max < aux->num)
		{
			max = aux->num;
			max_index = aux->index;
		}
		aux = aux->next;
	}
	size = ft_blstsize(*stack);
	if (max_index < size / 2)
		return (max_index);
	return (0);
}

void	order(t_blist **a)
{
	while (!is_it_ordered(*a))
	{
		if (is_max_above(a))
		{
			while (!is_it_ordered(*a))
				ra_mov(a, PRINT);
		}
		else
		{
			while (!is_it_ordered(*a))
				rra_mov(a, PRINT);
		}
	}
}
