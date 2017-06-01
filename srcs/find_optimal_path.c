/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 14:11:49 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 19:21:26 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Compare the efficiency of rotations on our stacks: Both forward, Both
** rotated in reverse. Stack A forward and B in reverse or A in reverse and B
** forward. Returns an int/"signal" notating optimal path.
*/

static int	calc_shortest_route(t_swap *sa)
{
	int		attempt[4];

	ft_bzero(attempt, sizeof(int) * 4);
	attempt[0] = MAX(sa->move_req_fw, sa->sb_req_fw) + 1;
	attempt[1] = MAX(sa->move_req_bw, sa->sb_req_bw) + 1;
	attempt[2] = sa->move_req_fw + sa->sb_req_bw + 1;
	attempt[3] = sa->move_req_bw + sa->sb_req_fw + 1;
	sa->optimal_path = ft_smallest_int(attempt, 4);
	return (attempt[sa->optimal_path]);
}

/*
** Calculates the number of moves each element needs to be sorted in the given
** data set, selects the optimal order of operations. Note that optimal is
** considered the path that is most operation efficient.
*/

t_swap		*find_optimal_path(t_swap *sa)
{
	t_swap	*optimal_moves;

	sa->moves_req = calc_shortest_route(sa);
	optimal_moves = sa;
	sa = sa->next;
	while (sa)
	{
		sa->moves_req = calc_shortest_route(sa);
		if (sa->moves_req < optimal_moves->moves_req)
			optimal_moves = sa;
		sa = sa->next;
	}
	return (optimal_moves);
}
