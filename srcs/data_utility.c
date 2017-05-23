/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:47:25 by tpan              #+#    #+#             */
/*   Updated: 2017/05/21 18:25:46 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**
*/

void		append_node(t_swap **stack, t_swap *to_add)
{
	t_swap	*tmp_stack;

	if (!to_add || !stack)
		return ;
		tmp_stack = *stack;
	if (!stack)
		*stack = to_add;
	else
	{
		tmp_stack = *stack;
		while (tmp_stack->next)
			tmp_stack = tmp_stack->next;
		tmp_stack->next = to_add;
	}
}

int		stack_length(t_swap *stack)
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

