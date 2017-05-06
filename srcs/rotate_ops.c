/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:35:17 by tpan              #+#    #+#             */
/*   Updated: 2017/05/05 20:57:06 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Shift all elements of stack a up by 1. The first element becomes the last.
*/

void		ra(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	rotate_forward(stacka);
	tracker->counter++;
	print_output(stacka, stackb, tracker);
}

/*
** Shift all elements of stack b up by 1. First elem becomes the last.
*/

void		rb(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	rotate_forward(stackb);
	tracker->counter++;
	print_output(stacka, stackb, tracker);
}

/*
** Equivalent to ra and rb at the same time, shift both stacks up by 1, first
** elems become last.
*/

void		rr(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	rotate_forward(stacka);
	rotate_forward(stackb);
	tracker->counter++;
	print_output(stacka, stackb, tracker);
}
