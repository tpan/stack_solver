/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:59:02 by tpan              #+#    #+#             */
/*   Updated: 2017/05/23 23:26:34 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Calculate the amount of RR we can do in order to equalize and move to other
** ops
*/

t_op		*do_rr(t_swap *element, t_op *op)
{
	int			i;
	int			rot;
	int			rot_diff;

	i = 0;
	op = (t_op *)malloc(sizeof(t_op) * (element->moves_req +1));
	rot_diff = MAX(element->move_req_fw, element->sb_req_fw) -
				MIN(element->move_req_fw, element->sb_req_fw);
	rot = MAX(element->move_req_fw, element->sb_req_fw) - rot_diff;
	while (i < rot)
		op[i++] = RR;
	rot = MAX(element->move_req_fw, element->sb_req_fw);
	if (element->move_req_fw > element->sb_req_fw)
		while (i < rot)
			op[i++] = RA;
	else if (element->move_req_fw <= element->move_req_fw)
		while (i < rot)
			op[i++] = RB;
	op[i++] = PB;
	op[i] = 0;
	return (op);
}

t_op		*do_rrr(t_swap *element, t_op *op)
{
	int		i;
	int		rot;
	int		rot_diff;

	i = 0;
	op = (t_op *)malloc(sizeof(t_op) * (element->moves_req +1));
	rot_diff = MAX(element->move_req_bw, element->sb_req_bw) -
				MIN(element->move_req_bw, element->sb_req_bw);
	rot = MAX(element->move_req_bw, element->sb_req_bw) - rot_diff;
	while (i < rot)
		op[i++] = RRR;
	rot = MAX(element->move_req_bw, element->sb_req_bw);
	if (element->move_req_bw > element->sb_req_bw)
		while (i < rot)
			op[i++] = RRA;
	else if (element->move_req_fw <= element->move_req_fw)
		while (i < rot)
			op[i++] = RRB;
	op[i++] = PB;
	op[i] = 0;
	return (op);
}
