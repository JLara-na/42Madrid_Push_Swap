/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ainit_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:18:39 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 01:30:32 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * 	Alphabet definitions
**/
void	alphabet_init(t_automata *a)
{
	a->alphabet = malloc(4 * (sizeof(char *)));
	a->alphabet[0] = ft_strdup(" ");
	a->alphabet[1] = ft_strdup("-+");
	a->alphabet[2] = ft_strdup("0123456789");
	a->alphabet[3] = NULL;
}

/**
 *	Alphabet free 
**/
void	free_alphabet(t_automata *a)
{
	int	i;

	i = -1;
	while (a->alphabet[++i])
		free(a->alphabet[i]);
	free(a->alphabet);
}

/**
 *	Simple actions, they trigger when entering a state.
**/
void	sactions_init(t_automata *a)
{
	a->fsa[INVALID] = parsing_error;
	a->fsa[NEGATIVE] = negative_alone;
}

/**
 *	Transition actions, they trigger when going
 * 		from one state to another.
**/
void	tactions_init(t_automata *a)
{
	a->fta[DIGIT][SPACES] = getnum;
}
