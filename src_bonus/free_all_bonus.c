/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:23:57 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 00:32:27 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stacks(t_blist **stack_a, t_blist **stack_b)
{
	t_blist	*a;
	t_blist	*b;

	a = *stack_a;
	b = *stack_b;
	while (a)
	{
		free(a);
		a = a->next;
	}
	while (b)
	{
		free(b);
		b = b->next;
	}
}

void	free_and_exit(t_blist **s_a, t_blist **s_b, char *move)
{
	free_stacks(s_a, s_b);
	free(move);
	terminate(NULL);
}
