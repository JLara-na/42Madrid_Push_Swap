/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:35:05 by jvasquez          #+#    #+#             */
/*   Updated: 2024/01/29 20:01:52 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_automata
{
	void	*data;
	char	**alphabet;
	char	*str;
	int		state;
	int		ostate;
	int		i;
	int		j;
	void	(*fsa[20])(struct s_automata *a, void	*data);
	void	(*fta[20][20])(struct s_automata *a, void	*data);
	int		(*get_state)(int state, int abc_idx);
}	t_automata;

int		evaluate(t_automata *a);
