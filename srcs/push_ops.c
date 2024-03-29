/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:18:30 by tpan              #+#    #+#             */
/*   Updated: 2017/05/13 17:16:07 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pa(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	push_on_top(sa, sb);
	tracker->counter++;
	tracker->current_operation = PA;
	print_output(sa, sb, tracker);
}

void		pb(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	push_on_top(sb, sa);
	tracker->counter++;
	tracker->current_operation = PB;
	print_output(sa, sb, tracker);
}
