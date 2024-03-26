/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:20:49 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 01:30:12 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pa_mov(t_blist **stack_a, t_blist **stack_b, int print)
{
	t_blist	*tmp;

	if (*stack_b)
	{
		tmp = ft_blstnew((*stack_b)->num, 0);
		tmp->next = *stack_a;
		*stack_a = tmp;
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
		fix_index(stack_a);
		fix_index(stack_b);
		if (print)
			ft_putendl_fd(PUSH_A, 1);
	}
	else
		terminate(ERROR_PA);
	return (1);
}

int	pb_mov(t_blist **stack_a, t_blist **stack_b, int print)
{
	t_blist	*tmp;

	if (*stack_a)
	{
		tmp = ft_blstnew((*stack_a)->num, 0);
		tmp->next = *stack_b;
		*stack_b = tmp;
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
		fix_index(stack_a);
		fix_index(stack_b);
		if (print)
			ft_putendl_fd(PUSH_B, 1);
	}
	else
		terminate(ERROR_PB);
	return (1);
}
