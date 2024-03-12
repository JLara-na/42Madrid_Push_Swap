/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:06:55 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/12 21:18:05 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int apply_moves_rr(t_blist **s, t_move *s_a, t_move *s_b, int move)
{
	int moves;
	
	moves = 0;
	if (move == 1 && (*s_a).ra && (*s_b).rb)
	{
		(*s)->moves.moves.rr++;
		(*s_a).ra--;
		(*s_b).rb--;
	}
	if (move == 2)
	{
		(*s)->moves.moves.rrr++;
		(*s_a).rra--;
		(*s_b).rrb--;
	}
	if (move == 3)
		moves = ((*s)->moves.moves.ra + (*s)->moves.moves.rb + (*s)->moves.moves.rr + (*s)->moves.moves.rra + (*s)->moves.moves.rrb + (*s)->moves.moves.rrr);
	return (moves);
}

void apply_moves_rab(t_blist **s, t_move *s_a, t_move *s_b, int move)
{
	if (move == 1)
	{
		(*s)->moves.moves.ra++;
		(*s_a).ra--;
	}
	if (move == 2)
	{
		(*s)->moves.moves.rra++;
		(*s_a).rra--;
	}
	if (move == 3)
	{
		(*s)->moves.moves.rb++;
		(*s_b).rb--;
	}
	if (move == 4)
	{
		(*s)->moves.moves.rrb++;
		(*s_b).rrb--;
	}
}

void	join_moves(t_blist **stack_a, t_blist **stack_b)
{
	t_move	mov_a;
	t_move	mov_b;

	mov_a = (*stack_a)->moves.moves_a;
	mov_b = (*stack_b)->moves.moves_b;
	while (mov_a.ra > 0 && mov_b.rb > 0)
		apply_moves_rr(stack_a, &mov_a, &mov_b, 1);
	while (mov_a.rra > 0 && mov_b.rrb > 0)
		apply_moves_rr(stack_a, &mov_a, &mov_b, 2);
	while (mov_a.ra > 0)
		apply_moves_rab(stack_a, &mov_a, &mov_b, 1);
	while (mov_b.rb > 0)
		apply_moves_rab(stack_a, &mov_a, &mov_b, 3);
	while (mov_a.rra > 0)
		apply_moves_rab(stack_a, &mov_a, &mov_b, 2);
	while (mov_b.rrb > 0)
		apply_moves_rab(stack_a, &mov_a, &mov_b, 4);
	(*stack_a)->moves.cost = apply_moves_rr(stack_a, &mov_a, &mov_b, 3);
}

//quiero que esta funcion ponga el coste y los moves que hay que hacer en todos los nodos de a

void    check_cost_a_to_b(t_blist **stack_a, t_blist **stack_b, int index)
{
	t_blist	*head_b;
	int i;
	
	(void)stack_a;
	head_b = *stack_b;
    i = 0;
	while ((*stack_b)->index != index)
		*stack_b = (*stack_b)->next;
	join_moves(stack_a, stack_b);
	*stack_b = head_b;
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

void	get_moves_a_to_b(t_blist **stack_a, t_blist **stack_b)
{
	t_blist	*head_a;
	t_blist	*head_b;
	int		i;
	int		j;
	int		index;
	
	head_a = *stack_a;
	head_b = *stack_b;
	i = ft_blstsize(*stack_a);
	j = 0;
	while (i--)
	{
		index = check_index_a_to_b(stack_a, stack_b, ft_blstsize(*stack_b));
		*stack_b = head_b;
		check_cost_a_to_b(stack_a, stack_b, index);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
}

void	get_moves_a(t_blist **stack_a)
{
	t_blist	*head_a;
	int		a_size;
	int		a_count;

	head_a = *stack_a;
	a_size = ft_blstsize(*stack_a);
	a_count = a_size;
	while (a_count--)
	{
		if ((*stack_a)->index <= a_size / 2)
			(*stack_a)->moves.moves_a.ra = ((*stack_a)->index);
		else
			(*stack_a)->moves.moves_a.rra = (a_size - (*stack_a)->index);
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head_a;
}

void	get_moves_b(t_blist **stack_b)
{
	t_blist	*head_b;
	int		b_size;
	int		b_count;

	head_b = *stack_b;
	b_size = ft_blstsize(*stack_b);
	b_count = b_size;
	while (b_count--)
	{
		if ((*stack_b)->index <= b_size / 2)
		{
			(*stack_b)->moves.moves_b.rb = ((*stack_b)->index);
			(*stack_b)->moves.moves_b.rrb = 0;
		}
		else
		{
			(*stack_b)->moves.moves_b.rrb = (b_size - (*stack_b)->index);
			(*stack_b)->moves.moves_b.rb = 0;
		}
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = head_b;
}
int	get_cheapest(t_blist **stack_a)
{
	t_blist	*head_a;
	int size;
	int	cheap_index;
	int	min;
	
	head_a = (*stack_a);
	size = ft_blstsize(*stack_a);
	cheap_index = 0;
	min = (*stack_a)->moves.cost;
	while (size--)
	{
		if ((*stack_a)->moves.cost < min)
		{
			min = (*stack_a)->moves.cost;
			cheap_index = (*stack_a)->index;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	return (cheap_index);
}

int	get_cheapest_index(t_blist **stack_a, t_blist **stack_b)
{
	get_moves_a(stack_a);
	get_moves_b(stack_b);
	get_moves_a_to_b(stack_a, stack_b);
	return (get_cheapest(stack_a));
}

void	do_moves(t_blist **stack_a, t_blist **stack_b)
{
	while ((*stack_a)->moves.moves.rr-- > 0)
		rr_mov(stack_a, stack_b, PRINT);
	while ((*stack_a)->moves.moves.rrr-- > 0)
		rrr_mov(stack_a, stack_b, PRINT);
	while ((*stack_a)->moves.moves.ra-- > 0)
		ra_mov(stack_a, PRINT);
	while ((*stack_a)->moves.moves.rra-- > 0)
		rra_mov(stack_a, PRINT);
	while ((*stack_a)->moves.moves.rb-- > 0)
		rb_mov(stack_b, PRINT);
	while ((*stack_a)->moves.moves.rrb-- > 0)
		rrb_mov(stack_b, PRINT);
	pb_mov(stack_a, stack_b, PRINT);
}

void	send_index_to_b(t_blist	**stack_a, t_blist	**stack_b, int	index)
{
	t_blist	*head_a;

	head_a = (*stack_a);
	while ((*stack_a)->index != index)
		*stack_a = (*stack_a)->next;
	do_moves(stack_a, stack_b);
}
void	clear_move_costs(t_blist **stack_a)
{
	t_blist	*head_a;
	int		size_a;

	size_a = ft_blstsize(*stack_a);
	head_a = (*stack_a);
	while (size_a--)
	{
		(*stack_a)->moves.cost = 0;
		(*stack_a)->moves.moves.ra = 0;
		(*stack_a)->moves.moves.rb = 0;
		(*stack_a)->moves.moves.rr = 0;
		(*stack_a)->moves.moves.rra = 0;
		(*stack_a)->moves.moves.rrb = 0;
		(*stack_a)->moves.moves.rrr = 0;
	}
	*stack_a = head_a;
}

/*void	prepare_a(t_blist	**stack_a, int	b_num)
{
	ft_putendl_fd("ME CAGO EN DIOS", 1);
	if ((*stack_a)->num > b_num)
		ra_mov(stack_a, PRINT);
	if ((*stack_a)->next->next->num > b_num && (*stack_a)->next->num < b_num)
		rra_mov(stack_a, PRINT);
}*/

void	going_a(t_blist **stack_a, t_blist **stack_b)
{
	int	size_b;
	int f;
	int s;
	int t;
	static int fm;
	static int sm;
	static int tm;

	f = (*stack_a)->num;
	s = (*stack_a)->next->num;
	t = (*stack_a)->next->next->num;
	size_b = ft_blstsize(*stack_b);
	while (size_b--)
	{
		if ((*stack_b)->num < t && (*stack_b)->num > s && fm++ == 0)
			rra_mov(stack_a, PRINT);
		if ((*stack_b)->num < s && (*stack_b)->num > f && sm++ == 0)
			rra_mov(stack_a, PRINT);
		if ((*stack_b)->num < f && tm++ == 0)
			rra_mov(stack_a, PRINT);
		pa_mov(stack_a, stack_b, PRINT);
	}
}

int	max_in_stack(t_blist	**stack)
{
	t_blist *aux;
    int     max;
    int		size;

	size = ft_blstsize(*stack);
    aux = *stack;
    max = aux->num;
    while (size--)
    {
        if (max < aux->num)
            max = aux->num;
        aux = aux->next;
    }
	return (max);
}

void	sort_big(t_blist **stack_a, t_blist **stack_b, int size)
{
	int	index;
	
	(void)size;
	pb_mov(stack_a, stack_b, PRINT);
	pb_mov(stack_a, stack_b, PRINT);
	while (ft_blstsize(*stack_a) > 3)
	{
		index = get_cheapest_index(stack_a, stack_b);
		send_index_to_b(stack_a, stack_b, index);
		clear_move_costs(stack_a);
	}
	sort_three(stack_a);
	while(max_in_stack(stack_b) != (*stack_b)->num)
	{
		if (max_in_stack(stack_b) == 1)
			rrb_mov(stack_b, PRINT);
		else
			rb_mov(stack_b, PRINT);
	}
	going_a(stack_a, stack_b);
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
		sort_big(stack_a, stack_b, size);
}