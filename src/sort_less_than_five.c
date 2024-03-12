/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:15:27 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/12 20:31:43 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     get_lower_index(t_blist **stack)
{
    t_blist *aux;
    int     position;
    int     lowest;
    
    
    aux = *stack;
    lowest = aux->num;
    position = 0;
    while (aux->next != NULL)
    {
        if (lowest > aux->num)
        {
            lowest = aux->num;
            position = aux->index;
        }
        aux = aux->next;
    }
    if (lowest > aux->num)
    {
            lowest = aux->num;
            position = aux->index;
    }
    return (position);
}

void    lowest_to_b(t_blist **stack_a, t_blist **stack_b)
{
    int position;
    int size;
    int i;
    
    i = 0;
    size = ft_blstsize(*stack_a);
    position = get_lower_index(stack_a);
    if (position == 1)
        sa_mov(stack_a, PRINT);
    else if (position > (size / 2))
        while (position < size--)
            rra_mov(stack_a, PRINT);
    else
        while (position > i++)
            ra_mov(stack_a, PRINT);
    pb_mov(stack_a, stack_b, PRINT);
}

void	sort_three(t_blist **stack_a)
{
    int one;
    int two;
    int thr;

    one = (*stack_a)->num;
	two = (*stack_a)->next->num;
	thr = (*stack_a)->next->next->num;
    
    if (one < thr)
    {
        sa_mov(stack_a, PRINT);
        if (two > thr)
            ra_mov(stack_a, PRINT);
    }
    else if (one > two && one > thr)
    {
        ra_mov(stack_a, PRINT);
        if (two > thr)
            sa_mov(stack_a, PRINT);
    }
    else
        rra_mov(stack_a, PRINT);
}

void    sort_four_five(t_blist   **stack_a, t_blist  **stack_b, int size)
{
    if (size == 5)
        lowest_to_b(stack_a, stack_b);
    lowest_to_b(stack_a, stack_b);
    if (!is_it_ordered(*stack_a))
        sort_three(stack_a);
    if (size == 5)
        pa_mov(stack_a, stack_b, PRINT);
	pa_mov(stack_a, stack_b, PRINT);
}
