/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:18:07 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 01:30:28 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*

	AUTOMATA STATES MATRIX

const int states[][4] = {
	//  \s, -, D, ^
		{0, 1, 3, 2},   // 0 Empty input
		{2, 2, 3, 2},   // 1 Negative sign found
		{2, 2, 2, 2},   // 2 Invalid Character
		{4, 2, 3, 2},   // 3 Digit found
		{4, 1, 3, 2},   // 4 Space after Digits
	};
*/

int	get_state(int i, int j)
{
	const int	states[][4] = {
	{0, 1, 3, 2},
	{2, 2, 3, 2},
	{2, 2, 2, 2},
	{4, 2, 3, 2},
	{4, 1, 3, 2},
	};

	return (states[i][j]);
}

void	automata_init(t_automata *a, void *data)
{
	ft_bzero(a, sizeof(t_automata));
	a->data = data;
	alphabet_init(a);
	sactions_init(a);
	tactions_init(a);
	a->get_state = get_state;
}

int	ft_chrpos(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	idx(char *alphabet[], char c)
{
	int	i;

	i = -1;
	while (alphabet[++i])
		if (ft_chrpos(alphabet[i], c) != -1)
			return (i);
	return (i);
}

int	evaluate(t_automata *a)
{
	a->ostate = 0;
	a->i = -1;
	while (++a->i < (int)ft_strlen(a->str))
	{
		a->state = a->get_state(a->state, idx(a->alphabet, a->str[a->i]));
		if (a->fsa[a->state])
			a->fsa[a->state](a, a->data);
		if (a->fta[a->ostate][a->state])
			a->fta[a->ostate][a->state](a, a->data);
		a->ostate = a->state;
	}
	return (a->state);
}
