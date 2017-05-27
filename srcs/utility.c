/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:47:25 by tpan              #+#    #+#             */
/*   Updated: 2017/05/26 22:16:18 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Appends an element to the stack list.
*/

void		append_node(t_swap **stack, t_swap *to_add)
{
	t_swap	*tmp_stack;

	if (!to_add || !stack)
		return ;
		tmp_stack = *stack;
	if (!*stack)
		*stack = to_add;
	else
	{
		tmp_stack = *stack;
		while (tmp_stack->next)
			tmp_stack = tmp_stack->next;
		tmp_stack->next = to_add;
	}
}

int		stack_len(t_swap *stack)
{
	int		i;

	i = 0;
	if (stack)
	{
		i++;
		while(stack->next)
		{
			stack = stack->next;
			i++;
		}
	}
	return (i);
}

/*
** Frees the remaining stack at the end of the program.
*/

void		free_stack(t_swap *stack)
{
	t_swap *tmp_stack;

	tmp_stack = stack;
	while (stack)
	{
		stack = stack->next;
		free(tmp_stack);
		tmp_stack = stack;
	}
}

/*
** Frees the stack and throws an error.
*/

t_swap		*invalid_input_error(t_swap *sa)
{
	free_stack(sa);
	ft_printf(RED"Error\n"RESET);
	exit(EXIT_FAILURE);
}
