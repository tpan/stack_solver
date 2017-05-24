/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 21:33:28 by tpan              #+#    #+#             */
/*   Updated: 2017/05/23 22:36:26 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Finds the values that precede and follow the current value that is inserted
** Sets the pointer to the 0th index if the value is smallest.
*/

static void	find_next(int value, int *after, int *b_arr, int b_len)
{
	int		i;
	int		smallest;

	i = 0;
	smallest = b_arr[b_len - 1];
	if (value < smallest)
		*after = b_arr[0];
	else
	{
		i = 0;
		while (b_arr[i] > value)
			i++;
		*after = b_arr[i];
	}
}

/*
** Calculates the correct insertion point for a given value, stack must remain
** sorted/ we assume the stack is sorted.
*/

static int	find_sb_target_depth(int value, t_swap *sb, int *b_arr, int b_len)
{
	int		target_depth;
	int		after;

	if (b_arr && b_len > 1)
		find_next(value, &after, b_arr, b_len);
	else if (b_arr)
		after = b_arr[0];
	target_depth = 0;
	while (sb)
	{
		if (after == sb->value)
			return (target_depth);
		sb = sb->next;
		target_depth++;
	}
	return (target_depth);
}

/*
** Calculate the amount of rotations we have to execute in order to insert our
** element. Stack b ALWAYS remains sorted.
*/

void		calculate_moves(t_swap *sa, t_swap *sb, t_tracker *tracker)
{
	int		a_cur_depth;
	int		b_target_depth;
	int		*b_vals_in_order;

	a_cur_depth = 0;
	tracker->a_height = stack_len(sa);
	tracker->b_height = stack_len(sb);
	b_vals_in_order = create_b_value_array(sb, tracker, &b_vals_in_order);
	while (sa)
	{
		sa->move_req_fw = a_cur_depth;
		sa->move_req_bw = 
				tracker->a_height == 1 ? 0 : tracker->a_height - a_cur_depth;
		b_target_depth = find_sb_target_depth(sa->value, sb, b_vals_in_order,
															tracker->b_height);
		sa->sb_req_fw = b_target_depth;
		sa->sb_req_bw = tracker->b_height - b_target_depth;
		sa = sa->next;
		a_cur_depth++;
	}
	free(b_vals_in_order);
}
