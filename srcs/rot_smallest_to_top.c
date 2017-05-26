/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_smallest_to_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:59:03 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 21:41:52 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		find_smallest(t_swap *sb)
{
	int			i;
	int			sm_index;
	int			curr_small;

	i = 0;
	sm_index = i;
	curr_small = sb->value;
	sb = sb->next;
	while (sb)
	{
		i++;
		if (sb->value > curr_small)
		{
			curr_small = sb->value;
			sm_index = i;
		}
		sb = sb->next;
	}
	return (sm_index);
}

static void		fill_ops(t_op *ops, t_op rot_code, int rot)
{
	int			i;

	i = 0;
	while (i < rot)
	{
		if (rot_code == RRA)
			ops[i++] = RRA;
		else if (rot_code == RA)
			ops[i++] = RA;
	}
}

void			rot_smallest_to_top(t_swap **sa, t_swap **sb,
															t_tracker *tracker)
{
	t_op	*ops;
	int		i;
	int		sm_index;
	int		rot;
	t_op	rot_code;

	sm_index = find_smallest(*sb);
	if (stack_len(*sb) - sm_index < sm_index)
	{
		rot = stack_len(*sb) - sm_index;
		rot_code = RRA;
	}
	ops = (t_op *)malloc(sizeof(t_op) * (rot + 1));
	ft_bzero(ops, sizeof(t_op) * (rot + 1));
	fill_ops(ops, rot_code, rot);
	i = 0;
	while (ops && ops[i])
		execute_instructions(sa, sb, tracker, ops[i++]);
	free(ops);
}
