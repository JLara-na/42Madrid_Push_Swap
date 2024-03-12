/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:46:33 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/12 21:20:09 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	leak(void)
{
	system("leaks -q push_swap");
}

void	terminate(char *error_msg)
{
	//(void)error_msg;
	//ft_putstr_fd(RED, 2);
	ft_putendl_fd(error_msg, 2);
	//ft_putstr_fd(DEF_COLOR, 2);
	atexit(leak);
	ft_putendl_fd("Error", 1);
	exit(EXIT_SUCCESS);
}

void	arg_handler(int argc, char **argv, t_automata *a, t_blist **stack_one)
{
	int	i;
	int	state;

	(void) stack_one;
	if (argc < 2)
		terminate(NULL);
	i = 0;
	while (argv[++i])
	{
		a->str = argv[i];
		state = evaluate(a);
		if (state == DIGIT)
			getnum(a, stack_one);
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

	/*ft_putendl_fd("STACK_A", 1);
	for(t_blist* it = stack_a; it != NULL; it = it->next)
	{
		printf("--> %p\n", it);
		printf("\t index -->  %i\n", it->index);
		printf("\t num   -->  %i\n", it->num);
		printf("\t next  -->  %p\n", it->next);
		printf("\t prev  -->  %p\n", it->prev);
	}
	ft_putendl_fd("STACK_B", 1);
	if(stack_b != NULL)
	{
		for(t_blist* ot = stack_b; ot != NULL; ot = ot->next)
		{
			printf("--> %p\n", ot);
			printf("\t index -->  %i\n", ot->index);
			printf("\t num   -->  %i\n", ot->num);
			printf("\t next  -->  %p\n", ot->next);
			printf("\t prev  -->  %p\n", ot->prev);
		}
	}
	*/
	sort_stack(&stack_a, &stack_b, ft_blstsize(stack_a));

	//ft_putendl_fd("STACK_A", 1);
	for(t_blist* it = stack_a; it != NULL; it = it->next)
	{
	//	printf("--> %p\n", it);
	//	printf("\t index -->  %i\n", it->index);
	//	printf("\t num   -->  %i\n", it->num);
	//	printf("\t ra    -->  %i\n", it->moves.moves.ra);
	//	printf("\t rb    -->  %i\n", it->moves.moves.rb);
	//	printf("\t rr    -->  %i\n", it->moves.moves.rr);
	//	printf("\t rra   -->  %i\n", it->moves.moves.rra);
	//	printf("\t rrb   -->  %i\n", it->moves.moves.rrb);
	//	printf("\t rrr   -->  %i\n", it->moves.moves.rrr);
	//	printf("\t COST  -->  %i\n", it->moves.cost);
	//	printf("\t next  -->  %p\n", it->next);
	//	printf("\t prev  -->  %p\n", it->prev);
		free(it);
	}
	
	//ft_putendl_fd("STACK_B", 1);
	for(t_blist* ot = stack_b; ot != NULL; ot = ot->next)
	{
	//	printf("--> %p\n", ot);
	//	printf("\t index -->  %i\n", ot->index);
	//	printf("\t num   -->  %i\n", ot->num);
	//	printf("\t rb    -->  %i\n", ot->moves.moves_b.rb);
	//	printf("\t rrb   -->  %i\n", ot->moves.moves_b.rrb);
	//	printf("\t next  -->  %p\n", ot->next);
	//	printf("\t prev  -->  %p\n", ot->prev);
		free(ot);
	}
	
	//atexit(leak);
	return (1);
}
