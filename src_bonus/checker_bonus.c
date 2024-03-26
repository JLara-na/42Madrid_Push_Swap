/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:30:40 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 01:30:21 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_it_repeated(int num, t_blist *blist)
{
	t_blist	*new;

	new = blist;
	while (new)
	{
		if (num == new->num)
			terminate(NULL);
		new = new->next;
	}
	return (1);
}

int	is_it_rev_ordered(t_blist *blist)
{
	t_blist	*new;
	int		buf;

	if (blist)
	{
		new = blist;
		buf = new->num;
		new = new->next;
		while (buf > new->num)
		{
			if (new->next)
			{
				buf = new->num;
				new = new->next;
			}
			else
				return (1);
		}
	}
	else
		return (-1);
	return (0);
}

int	is_it_ordered(t_blist *blist)
{
	t_blist	*new;
	int		buf;

	new = blist;
	buf = new->num;
	new = new->next;
	while (buf < new->num)
	{
		if (new->next)
		{
			buf = new->num;
			new = new->next;
		}
		else
			return (1);
	}
	return (0);
}

void	stack_checker(t_blist **stack_one)
{
	t_blist	*checking;
	int		num;
	int		size;

	checking = *stack_one;
	size = ft_blstsize(checking);
	if (size < 2)
		exit(EXIT_SUCCESS);
	while (checking)
	{
		num = checking->num;
		checking = checking->next;
		is_it_repeated(num, checking);
	}
	checking = *stack_one;
	if (is_it_ordered(checking))
		exit(EXIT_SUCCESS);
}
