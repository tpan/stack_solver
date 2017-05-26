/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:42:24 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 22:03:28 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Execute the instruction for the given operation code.
*/

void		execute_instructions(t_swap **stack_a, t_swap **stack_b,
											t_tracker *tracker, t_op op)
{
	if (op == SA)
		sa(stack_a, stack_b, tracker);
	else if (op == SB)
		sb(stack_a, stack_b, tracker);
	else if (op == SS)
		ss(stack_a, stack_b, tracker);
	else if (op == PA)
		pa(stack_a, stack_b, tracker);
	else if (op == PB)
		pb(stack_a, stack_b, tracker);
	else if (op == RA)
		ra(stack_a, stack_b, tracker);
	else if (op == RB)
		rb(stack_a, stack_b, tracker);
	else if (op == RR)
		rr(stack_a, stack_b, tracker);
	else if (op == RRA)
		rra(stack_a, stack_b, tracker);
	else if (op == RRB)
		rrb(stack_a, stack_b, tracker);
	else if (op == RRR)
		rrr(stack_a, stack_b, tracker);
}

/*
** Pushes all stack b elements onto stack a, after stack b is sorted in reverse
** order.
**
*/

static void		final_push(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	t_op	*ops;
	int		i;

	rot_largest_to_top(sa, sb, tracker);
	ops = (t_op *)malloc(sizeof(t_op) * (tracker->counter + 1));
	i = 0;
	while (i < tracker->counter)
		ops[i++] = PA;
	ops[i] = 0;
	i = 0;
	while (ops && ops[i])
		execute_instructions(sa, sb, tracker, ops[i++]);
	free(ops);
}

/*
** Returns 1 if the stack is sorted, zero otherwise.
*/

int				is_sorted(t_swap *stack)
{
	int			prev_val;

	if (!stack)
		return (1);
	prev_val = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (prev_val >= stack->value)
			return (0);
		prev_val = stack->value;
		stack = stack->next;
	}
	return (1);
}

/*
** Calls stack sorting functions, trace from here for sorting.
*/

void			sort_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	int			i;
	t_swap		*optimal_path;
	t_op		*instructions;

	if (is_sorted(*sa))
		return ;
	while (*sa)
	{
		calculate_moves(*sa, *sb, tracker);
		optimal_path = find_optimal_path(*sa);
		instructions = init_ops(optimal_path, instructions);
		i = 0;
		while (instructions && instructions[i])
			execute_instructions(sa, sb, tracker, instructions[i++]);
		free(instructions);
	}
	if (!*sa || is_sorted(*sa))
		final_push(sa, sb, tracker);
	else
		ft_printf(RED"ERROR! sorting failed somehow!\n"RESET);
}
