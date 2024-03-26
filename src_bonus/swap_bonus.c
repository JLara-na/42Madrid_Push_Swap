/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:20:01 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 01:29:57 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sa_mov(t_blist **stack_a, int print)
{
	int	buff;

	if (ft_blstsize(*stack_a) > 1)
	{
		buff = (*stack_a)->num;
		(*stack_a)->num = (*stack_a)->next->num;
		(*stack_a)->next->num = buff;
		if (print)
			ft_putendl_fd(SWAP_A, 1);
	}
	else
		terminate(ERROR_SA);
	return (1);
}

int	sb_mov(t_blist **stack_b, int print)
{
	int	buff;

	if (ft_blstsize(*stack_b) > 1)
	{
		buff = (*stack_b)->num;
		(*stack_b)->num = (*stack_b)->next->num;
		(*stack_b)->next->num = buff;
		if (print)
			ft_putendl_fd(SWAP_B, 1);
	}
	else
		terminate(ERROR_SB);
	return (1);
}

int	ss_mov(t_blist **stack_a, t_blist **stack_b, int print)
{
	sa_mov(stack_a, 0);
	sb_mov(stack_b, 0);
	if (print)
		ft_putendl_fd(SWAP_BOTH, 1);
	return (1);
}
