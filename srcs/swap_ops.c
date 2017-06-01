/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:59:49 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 19:19:21 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sa(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	flip_the_top(stacka);
	tracker->counter++;
	tracker->current_operation = SA;
	print_output(stacka, stackb, tracker);
}

void		sb(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	flip_the_top(stackb);
	tracker->counter++;
	tracker->current_operation = SB;
	print_output(stacka, stackb, tracker);
}

void		ss(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	flip_the_top(stacka);
	flip_the_top(stackb);
	tracker->counter++;
	tracker->current_operation = SS;
	print_output(stacka, stackb, tracker);
}
