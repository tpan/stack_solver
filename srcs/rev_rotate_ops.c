/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 22:07:44 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 16:33:41 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rra(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_backward(sa);
	tracker->counter++;
	tracker->current_operation = RRA;
	print_output(sa, sb, tracker);
}

void		rrb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_backward(sb);
	tracker->counter++;
	tracker->current_operation = RRB;
	print_output(sa, sb, tracker);
}

void		rrr(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	rotate_backward(sa);
	rotate_backward(sb);
	tracker->counter++;
	tracker->current_operation = RRR;
	print_output(sa, sb, tracker);
}
