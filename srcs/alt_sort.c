/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:43:01 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 16:34:35 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Returns an int array with values from Stack A, sorted from small to large.
*/

int			*create_a_val_array(t_swap *stack, int **a_val_arr)
{
	int		i;
	int		slen;
	int		*tmp_arr;

	slen = stack_len(stack);
	if (!(tmp_arr = (int *)malloc(sizeof(int) * slen)))
		return (NULL);
	ft_bzero(tmp_arr, sizeof(int) * slen);
	i = 0;
	while (stack)
	{
		tmp_arr[i++] = stack->value;
		stack = stack->next;
	}
	*a_val_arr = ft_int_sort(tmp_arr, slen);
	free(tmp_arr);
	return (*a_val_arr);
}

/*
** In case of a data set of three we must resort to the three_sort.
*/

void		three_sort(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	int		*tmp_arr;
	int		sm;

	while (!is_sorted(*sa))
	{
		sm = tmp_arr[ft_smallest_int(create_a_val_array(*sa, &tmp_arr), 3)];
		free(tmp_arr);
		if (((*sa)->value == sm) || (((*sa)->value > sm) &&
									(*sa)->value < (*sa)->next->next->value))
			execute_instructions(sa, sb, tracker, SA);
		else if ((((*sa)->value) > (*sa)->next->value) &&
									((*sa)->value) > (*sa)->next->next->value)
		{
			execute_instructions(sa, sb, tracker, RA);
			execute_instructions(sa, sb, tracker, SA);
		}
		else
			execute_instructions(sa, sb, tracker, RRA);
	}
}

/*
** Alternative sort for small data sets. Start by looking at the top element,
** if this is the smallest in stack A then we push it to stack B. B will
** always be sorted in the reverse order and contain small elements.
** When stack A is sorted and has the smallest item on top then we push_swap
** stack B and merge the two stacks.
*/

void		bubblesque_sort(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	int		*tmp_arr;
	int		sm;
	int		slen;

	while (!is_sorted(*sa))
	{
		slen = stack_len(*sa);
		sm = tmp_arr[ft_smallest_int(create_a_val_array(*sa, &tmp_arr), slen)];
		free(tmp_arr);
		if (sm == (*sa)->value)
		{
			execute_instructions(sa, sb, tracker, PB);
			slen = stack_len(*sa);
		}
		else if ((*sa)->value > (*sa)->next->value)
			execute_instructions(sa, sb, tracker, SA);
		else
			execute_instructions(sa, sb, tracker, RA);
		if (ft_ints_arr_sorted(create_a_val_array(*sa, &tmp_arr), slen))
			rot_smallest_to_top(sa, sb, tracker);
		free(tmp_arr);
	}
	while (*sb)
		execute_instructions(sa, sb, tracker, PA);
}
