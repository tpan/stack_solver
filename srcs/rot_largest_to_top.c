/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_largest_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:59:03 by tpan              #+#    #+#             */
/*   Updated: 2017/05/26 08:50:00 by tpan             ###   ########.fr       */
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

void			rot_largest_to_top(t_swap **sa, t_swap **sb,
															t_tracker *tracker)
{
	t_op	*ops;
	int		i;
	int		lg_index;
	int		rot;
	t_op	rot_code;

	lg_index = find_largest(*sb);
	if (stack_len(*sb) - lg_index < lg_index)
	{
		rot = stack_len(*sb) - lg_index;
		rot_code = RRB;
	}
	else
	{
		rot = lg_index;
		rot_code = RB;
	}
	ops = (t_op *)malloc(sizeof(t_op) * (rot + 1));
	ft_bzero(ops, sizeof(t_op) * (rot + 1));
	fill_ops(ops, rot_code, rot);
	i = 0;
	while (ops && ops[i])
		execute_instructions(sa, sb, tracker, ops[i++]);
	free(ops);
}
