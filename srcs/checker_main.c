/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:19:05 by tpan              #+#    #+#             */
/*   Updated: 2017/05/27 17:20:48 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_op	str_to_opcode(char *line)
{
	if (ft_strequ(line, "sa"))
		return (SA);
	else if (ft_strequ(line, "sb"))
		return (SB);
	else if (ft_strequ(line, "ss"))
		return (SS);
	else if (ft_strequ(line, "pa"))
		return (PA);
	else if (ft_strequ(line, "pb"))
		return (PB);
	else if (ft_strequ(line, "ra"))
		return (RA);
	else if (ft_strequ(line, "rb"))
		return (RB);
	else if (ft_strequ(line, "rr"))
		return (RR);
	else if (ft_strequ(line, "rra"))
		return (RRA);
	else if (ft_strequ(line, "rrb"))
		return (RRB);
	else if (ft_strequ(line, "rrr"))
		return (RRR);
	else
		return (NOTVALID);
}

/*
** Parses and executes instruction list created by init_ops.
*/

static void			do_ops(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	char		*line;
	int			operation;

	operation = 1;
	while (operation != NOTVALID && get_next_line(0, &line))
	{
		operation = str_to_opcode(line);
		execute_instructions(sa, sb, tracker, operation);
	}
	if (operation == NOTVALID)
	{
		ft_printf(RED"Error\n");
		free_stack(*sa);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	t_swap		*sa;
	t_swap		*sb;
	t_tracker	tracker;
	char		**new_argv;

	ft_bzero(&tracker, sizeof(t_tracker));
	tracker.silence = 1;
	if (argc > 1)
	{
		if ((new_argv = parse_args(++argv)))
			sa = read_input_init_stack(new_argv, &tracker);
		else
			sa = read_input_init_stack(argv, &tracker);
		if (sa && !check_duplicates(sa))
		{
			do_ops(&sa, &sb, &tracker);
			if (is_sorted(sa) && sb == NULL)
				ft_printf(GREEN"OK\n"RESET);
			else
				ft_printf(RED"KO\n"RESET);
			if (new_argv)
				ft_tab_del(&new_argv);
		}
	}
	return (0);
}
