/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:15:55 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/26 01:30:15 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
static void	leak(void)
{
	system("leaks -q checker");
}
//atexit(leak);
*/

void	terminate(char *error_msg)
{
	(void)error_msg;
	ft_putendl_fd("Error", 2);
	exit(EXIT_SUCCESS);
}

void	do_move(t_blist **s_a, t_blist **s_b, char *move)
{
	if (!ft_strncmp(move, "ra\n", 3))
		ra_mov(s_a, 0);
	else if (!ft_strncmp(move, "rb\n", 3))
		rb_mov(s_b, 0);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr_mov(s_a, s_b, 0);
	else if (!ft_strncmp(move, "rra\n", 4))
		rra_mov(s_a, 0);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrb_mov(s_b, 0);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr_mov(s_a, s_b, 0);
	else if (!ft_strncmp(move, "sa\n", 3))
		sa_mov(s_a, 0);
	else if (!ft_strncmp(move, "sb\n", 3))
		sb_mov(s_b, 0);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss_mov(s_a, s_b, 0);
	else if (!ft_strncmp(move, "pa\n", 3))
		pa_mov(s_a, s_b, 0);
	else if (!ft_strncmp(move, "pb\n", 3))
		pb_mov(s_a, s_b, 0);
	else
		free_and_exit(s_a, s_b, move);
}

void	do_moves(t_blist **s_a, t_blist **s_b)
{
	char	*move;

	while (TRUE)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		do_move(s_a, s_b, move);
		free(move);
	}
	if (is_it_ordered(*s_a) && ft_blstsize(*s_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

void	arg_handler(int argc, char **argv, t_automata *a, t_blist **stack)
{
	int	i;
	int	state;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 0;
	while (argv[++i])
	{
		a->str = argv[i];
		state = evaluate(a);
		if (state == DIGIT)
			getnum(a, stack);
		a->j = 0;
		a->state = 0;
	}
	free_alphabet(a);
}

int	main(int argc, char **argv)
{
	t_automata	a;
	t_blist		*stack_a;
	t_blist		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	automata_init(&a, &stack_a);
	arg_handler(argc, argv, &a, &stack_a);
	stack_checker(&stack_a);
	do_moves(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
