/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:20:03 by tpan              #+#    #+#             */
/*   Updated: 2017/05/24 12:18:34 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

/*
** We find the relevant data with create_b_array and then initialize the data
** with populate_b_stack.
*/

static int	*populate_b_stack(t_swap *stack, int sm_index, int *b_val_arr)
{
	t_swap	*stack_begin;
	int		i;
	int		j;

	i = 0;
	stack_begin = stack;
	if (sm_index == 0)
		stack = stack->next;
	else
		while (i++ < sm_index)
			stack = stack->next;
	j = 0;
	while (stack)
	{
		b_val_arr[j++] = stack->value;
		stack = stack->next;
	}
	stack = stack_begin;
	i = 0;
	if (sm_index == 0)
		b_val_arr[j] = stack->value;
	else
		while (i++ < sm_index)
		{
			b_val_arr[j++] = stack->value;
			stack = stack->next;
		}
	return (b_val_arr);
}

/*
** Creates a list of values from stack b, starting from largest so we can
** easily locate our insertion point.
*/

int			*create_b_array(t_swap *stack, t_tracker *tracker, 
															int **b_val_arr)
{
	t_swap	*stack_begin;
	int		i;
	int		sm_index;
	int		smallest;

	if (!stack ||
		!(*b_val_arr = (int *)malloc(sizeof(int) * (tracker->b_height + 1))))
			return (NULL);
	ft_bzero(*b_val_arr, (sizeof(int) * (tracker->b_height +1)));
	i = 0;
	sm_index = 0;
	smallest = stack->value;
	stack_begin = stack;
	while (stack)
	{
		i++;
		if (stack->value < smallest)
		{
			smallest = stack->value;
			sm_index = i;
		}
		stack = stack->next;
	}
	return (populate_b_stack(stack_begin, sm_index, *b_val_arr));
}
