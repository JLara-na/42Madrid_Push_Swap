/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:33:32 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 01:30:10 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rra_mov(t_blist **stack_a, int print)
{
	int	buff;

	if (*stack_a)
	{
		while ((*stack_a)->next != NULL)
			(*stack_a) = (*stack_a)->next;
		while ((*stack_a)->prev != NULL)
		{
			buff = (*stack_a)->num;
			(*stack_a)->num = (*stack_a)->prev->num;
			(*stack_a)->prev->num = buff;
			(*stack_a) = (*stack_a)->prev;
		}
		if (print)
			ft_putendl_fd(REVERSE_ROTATE_A, 1);
	}
	else
		terminate(ERROR_RRA);
	return (1);
}

int	rrb_mov(t_blist **stack_b, int print)
{
	int	buff;

	if (*stack_b)
	{
		while ((*stack_b)->next != NULL)
			(*stack_b) = (*stack_b)->next;
		while ((*stack_b)->prev != NULL)
		{
			buff = (*stack_b)->num;
			(*stack_b)->num = (*stack_b)->prev->num;
			(*stack_b)->prev->num = buff;
			(*stack_b) = (*stack_b)->prev;
		}
		if (print)
			ft_putendl_fd(REVERSE_ROTATE_B, 1);
	}
	else
		terminate(ERROR_RRB);
	return (1);
}

int	rrr_mov(t_blist **stack_a, t_blist **stack_b, int print)
{
	rra_mov(stack_a, 0);
	rrb_mov(stack_b, 0);
	if (print)
		ft_putendl_fd(REVERSE_ROTATE_BOTH, 1);
	return (1);
}
