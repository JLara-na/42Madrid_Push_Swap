/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:30:31 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/12 20:07:13 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	fix_index(t_blist **stack)
{
	t_blist	*first;
	int		i;
	
	if (*stack)
	{
		i = 0;
		first = *stack;
		while ((*stack)->next != NULL)
		{
			(*stack)->index = i++;
			if ((*stack)->index == 0)
				(*stack)->prev = NULL;
			if ((*stack)->next)
				(*stack)->next->prev = (*stack);
			(*stack) = (*stack)->next;
		}
		(*stack)->index = i;
		*stack = first;
	}
}

t_blist	*ft_blstnew(int num, int index)
{
	t_blist	*blist;

	blist = malloc(sizeof(t_blist));
	if (!blist)
		return (NULL);
	blist->index = index;
	blist->num = num;
	blist->next = NULL;
	blist->prev = NULL;
	return (blist);
}

t_blist	*ft_blstlast(t_blist *blst)
{
	struct s_blist	*blist;

	if (!blst)
		return (NULL);
	blist = blst;
	while (blist->next != NULL)
		blist = blist->next;
	return (blist);
}

int	ft_blstsize(t_blist *blst)
{
	size_t	i;
	t_blist	*blist;

	i = 1;
	if (!blst)
		return (0);
	blist = blst;
	while (blist->next != NULL)
	{
		blist = blist->next;
		i++;
	}
	return (i);
}

void	ft_blstadd_back(t_blist **blst, t_blist *new)
{
	t_blist	*blist;

	if (!blst)
		return ;
	if (*blst == NULL)
		*blst = new;
	else
	{
		blist = ft_blstlast(*blst);
		blist->next = new;
		new->prev = blist;
	}
}
