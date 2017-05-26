/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_largest_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:59:03 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 17:22:01 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		find_largest(t_swap *sb)
{
	int			i;
	int			lg_index;
	int			curr_large;

	i = 0;
	lg_index = i;
	curr_large = sb->value;
	sb = sb->next;
	while (sb)
	{
		i++;
		if (sb->value > curr_large)
		{
			curr_large = sb->value;
			lg_index = i;
		}
		sb = sb->next;
	}
	return (lg_index);
}

static void		fill_ops(t_op *ops, t_op rot_code, int rot)
{
	int			i;

	i = 0;
	while (i < rot)
	{
		if (rot_code == RRB)
			ops[i++] = RRB;
		else if (rot_code == RB)
			ops[i++] = RB;
	}
}

void			rot_largest_to_top(t_swap **Sa, t_swap **sb,
															t_tracker *tracker)
{

}
