/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:51:25 by jlara-na          #+#    #+#             */
/*   Updated: 2024/02/21 21:14:10 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ra_mov(t_blist **stack_a, int print)
{
	int		buff;
	t_blist	*first;

	if (*stack_a)
	{
		first = *stack_a;
		while ((*stack_a)->next != NULL)
		{
			buff = (*stack_a)->num;
			(*stack_a)->num = (*stack_a)->next->num;
			(*stack_a)->next->num = buff;
			(*stack_a) = (*stack_a)->next;
		}
		*stack_a = first;
		if (print)
			ft_putendl_fd(ROTATE_A, 1);
	}
	else
		terminate(ERROR_RA);
	return (1);
}

int	rb_mov(t_blist **stack_b, int print)
{
	int		buff;
	t_blist	*first;

	if (*stack_b)
	{
		first = *stack_b;
		while ((*stack_b)->next != NULL)
		{
			buff = (*stack_b)->num;
			(*stack_b)->num = (*stack_b)->next->num;
			(*stack_b)->next->num = buff;
			(*stack_b) = (*stack_b)->next;
		}
		*stack_b = first;
		if (print)
			ft_putendl_fd(ROTATE_B, 1);
	}
	else
		terminate(ERROR_RB);
	return (1);
}

int	rr_mov(t_blist **stack_a, t_blist **stack_b, int print)
{
	ra_mov(stack_a, 0);
	rb_mov(stack_b, 0);
	if (print)
		ft_putendl_fd(ROTATE_BOTH, 1);
	return (1);
}
