/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:46:25 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 10:36:04 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Swap the top two items on a stack.(ie sa and sb)
*/

void		flip_the_top(t_swap **stack)
{
	t_swap		*a;
	t_swap		*b;
	t_swap		*c;

	if (stack_len(*stack) < 2)
		return ;
	a = *stack;
	b = (*stack)->next;
	c = (*stack)->next->next;
	*stack = b;
	(*stack)->next = a;
	(*stack)->next->next = c;
	return;
}

/*
** Pushs the top item from S2 and moves it onto the top of S1 (ie pa and pb)
*/

void	push_on_top(t_swap **s2, t_swap **s1)
{ 
	t_swap			*tmp;

	if (!*s1)
		return ;
	tmp =  *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
	return ;
}

/* 
** Rotates the stack forward (top of the stack goes to the bottom; ie rotate)
*/

void		rotate_forward(t_swap **stack)
{
	t_swap		*tmp;
	t_swap		*iter;

	if (stack_len(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	tmp->next = NULL;
	iter->next = tmp;
	return ;
}

/*
** Rotates the stack backward (bottom of the stack goes to the top)
*/

void		rotate_backward(t_swap **stack)
{
	t_swap		*tmp;
	t_swap		*iter;

	if (stack_len(*stack) < 2)
		return;
	tmp = *stack;
	iter = *stack;
	while (iter->next->next)
		iter = iter->next;
	*stack = iter->next;
	iter->next = NULL;
	(*stack)->next = tmp;
	return ;
}
