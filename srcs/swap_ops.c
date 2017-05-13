/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:59:49 by tpan              #+#    #+#             */
/*   Updated: 2017/05/11 18:17:03 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void		sa(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	if ((stack_length(*stacka) < 2) || (stack_length(*stackb) < 2))
		return ;
	
	flip_the_top(stacka);
	tracker->counter++;
	print_output(stacka, stackb, tracker);
}

void		sb(t_swap **stacka, t_swap **stackb, t_tracker *tracker)
{
	if ((stack_length(*stacka) < 2) || (stack_length(*stackb) < 2))
		return ;

	flip_the_top(stackb);
	tracker->counter++;
	print_output(stacka, stackb, tracker);
}

void		ss(t_swap **stacka,t_swap **stackb, t_tracker *tracker)
{
	flip_the_top(stacka);
	flip_the_top(stackb);
	tracker->counter++;
	print_output(stacka, stackb, tracker);
}
