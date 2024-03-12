/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:22:53 by jlara-na          #+#    #+#             */
/*   Updated: 2024/02/10 20:31:04 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	help_msg(void)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putendl_fd(MSG_HELP_ARG1, 1);
	ft_putstr_fd(DEF_COLOR, 1);
	ft_putendl_fd(MSG_HELP_ARG2, 1);
	ft_putendl_fd(MSG_HELP_ARG3, 1);
}

int	msg(int code)
{
	if (code == HELP)
		help_msg();
	return (1);
}
