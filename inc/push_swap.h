/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:36:00 by jlara-na          #+#    #+#             */
/*   Updated: 2024/03/12 20:01:35 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "automata.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

//-----------------------------------DEFINES----------------------------------//

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef HELP
#  define HELP 0
# endif

# define PRINT 1

typedef enum e_states
{
	EMPTY,
	NEGATIVE,
	INVALID,
	DIGIT,
	SPACES
}					t_states;

//-----------------------------------COLORS-----------------------------------//

# define CLEAR 			"\033[2J\033[1;1H"
# define DEF_COLOR 		"\033[0;39m"
# define GRAY 			"\033[0;90m"
# define RED 			"\033[0;91m"
# define RED_B 			"\033[0;91;5m"
# define GREEN 			"\033[0;92m"
# define GREEN_B 		"\033[0;92;5m"
# define YELLOW 		"\033[0;93m"
# define YELLOW_B 		"\033[0;93;5m"
# define BLUE 			"\033[0;94m"
# define BLUE_B 		"\033[0;94;5m"
# define MAGENTA 		"\033[0;95m"
# define MAGENTA_B	 	"\033[0;95;5m"
# define CYAN 			"\033[0;96m"
# define CYAN_B 		"\033[0;96;5m"
# define WHITE 			"\033[0;97m"
# define WHITE_B 		"\033[0;97;5m"

//------------------------------------MSG-------------------------------------//

# define MSG_HELP_ARG1 	"You can either pass one argument or many"
# define MSG_HELP_ARG2 	"Input format: ./push_swap 'number mumber number'"
# define MSG_HELP_ARG3 	"Input format: ./push_swap number number number"
# define MSG_4 			""

//----------------------------------ERRORS------------------------------------//

# define ERROR_ARG 		"This is an invalid argument: "
# define ERROR_ARG_NUM 	"Invalid number of arguments"
# define ERROR_LIMIT 	"Number out of limits"
# define ERROR_REPEAT 	"Some arguments are repeated"
# define ERROR_ORDER 	"These arguments are already ordered"
# define ERROR_SA		"UNABLE TO MAKE SA MOVEMENT"
# define ERROR_SB		"UNABLE TO MAKE SB MOVEMENT"
# define ERROR_PA		"UNABLE TO MAKE PA MOVEMENT"
# define ERROR_PB		"UNABLE TO MAKE PB MOVEMENT"
# define ERROR_RA		"UNABLE TO MAKE RA MOVEMENT"
# define ERROR_RB		"UNABLE TO MAKE RB MOVEMENT"
# define ERROR_RRA		"UNABLE TO MAKE RRA MOVEMENT"
# define ERROR_RRB		"UNABLE TO MAKE RRB MOVEMENT"

//-----------------------------------MOVES------------------------------------//

# define SWAP_A					"sa"
# define SWAP_B					"sb"
# define SWAP_BOTH				"ss"
# define PUSH_A					"pa"
# define PUSH_B					"pb"
# define ROTATE_A				"ra"
# define ROTATE_B				"rb"
# define ROTATE_BOTH			"rr"
# define REVERSE_ROTATE_A		"rra"
# define REVERSE_ROTATE_B		"rrb"
# define REVERSE_ROTATE_BOTH	"rrr"

//----------------------------DEFINING STRUCTURES-----------------------------//

typedef struct s_move
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_move;

typedef struct s_moves
{
	t_move			moves_a;
	t_move			moves_b;
	t_move			moves;
	int				cost;
}					t_moves;

typedef struct s_blist
{
	int				index;
	int				num;
	t_moves			moves;
	struct s_blist	*prev;
	struct s_blist	*next;
}					t_blist;

//---------------------------------FUNCTIONS----------------------------------//

int			msg(int code);
void		terminate(char *error_msg);
int			is_it_ordered(t_blist *blist);
int			is_it_rev_ordered(t_blist *blist);
void		stack_checker(t_blist **stack_one);

int    		get_lower_index(t_blist **stack);
void    	lowest_to_b(t_blist **stack_a, t_blist **stack_b);

void		sort_three(t_blist **stack_a);
void    	sort_four_five(t_blist   **stack_a, t_blist  **stack_b, int size);
void		sort_stack(t_blist	**stack_a, t_blist	**stack_b, int size);

int			sa_mov(t_blist	**stack_a, int print);
int			sb_mov(t_blist	**stack_b, int print);
int			ss_mov(t_blist	**stack_a, t_blist	**stack_b, int print);

int			pa_mov(t_blist	**stack_a, t_blist	**stack_b, int print);
int			pb_mov(t_blist	**stack_a, t_blist	**stack_b, int print);

int			ra_mov(t_blist	**stack_a, int print);
int			rb_mov(t_blist	**stack_b, int print);
int			rr_mov(t_blist	**stack_a, t_blist	**stack_b, int print);

int			rra_mov(t_blist	**stack_a, int print);
int			rrb_mov(t_blist	**stack_b, int print);
int			rrr_mov(t_blist	**stack_a, t_blist	**stack_b, int print);

int			ft_blstsize(t_blist *blst);
void		ft_blstadd_back(t_blist **blst, t_blist *new);
void		ft_blstiter(t_blist *blst, void (*f)(void *));
void		fix_index(t_blist	**stack);
t_blist		*ft_blstlast(t_blist *blst);
t_blist		*ft_blstnew(int num, int index);

//--------------------------------AUTOMATA_FT---------------------------------//

void			alphabet_init(t_automata *a);
void			sactions_init(t_automata *a);
void			tactions_init(t_automata *a);
void			parsing_error(t_automata *a, void *data);
void			getnum(t_automata *a, void *data);
void			automata_init(t_automata *a, void *data);
void			negative_alone(t_automata *a, void *data);
int				get_state(int i, int j);
void			free_alphabet(t_automata *a);

#endif
