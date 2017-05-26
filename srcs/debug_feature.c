/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_feature.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:16:50 by tpan              #+#    #+#             */
/*   Updated: 2017/05/26 15:23:33 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			log_operations(int current_op, t_tracker *tracker)
{
	t_swap		*new_op;

	new_op = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(new_op, sizeof(t_swap));
	new_op->value = current_op;
	append_node(&(tracker->op_log), new_op);
}

void		print_logs(t_swap *sa, t_tracker *tracker)
{
	t_swap		*log;

	log = tracker->op_log;
	while(log)
	{
		print_op_code(log->value);
		log = log->next;
	}
	ft_putnbr(stack_len(tracker->op_log));
	ft_putstr(" total operations.\n");
	if (is_sorted(sa))
		ft_printf("%sOK\n",GREEN ,RESET);
	else
		ft_printf("%sKO\n",GREEN ,RESET);
	free_stack(tracker->op_log);
}

char		*opcode_to_str(t_op code)
{
	if (code == SA)
		return (ft_strdup("sa"));
	else if (code == SB)
		return (ft_strdup("sb"));
	else if (code == SS)
		return (ft_strdup("ss"));
	else if (code == PA)
		return (ft_strdup("pa"));
	else if (code == PB)
		return (ft_strdup("pb"));
	else if (code == RA)
		return (ft_strdup("ra"));
	else if (code == RB)
		return (ft_strdup("rb"));
	else if (code == RR)
		return (ft_strdup("rr"));
	else if (code == RRA)
		return (ft_strdup("rra"));
	else if (code == RRB)
		return (ft_strdup("rrb"));
	else if (code == RRR)
		return (ft_strdup("rrr"));
	else
		return (ft_strdup("START"));
}

void		print_stacks(t_swap *sa, t_swap *sb, t_tracker *tracker)
{
	char *op;

	op = opcode_to_str(tracker->current_operation);
	ft_printf(UL "Stack A             Stack B\n" RESET);
	ft_printf(BOLD UL "----------  %3s  -----------\n" RESET, op);
	while (sa || sb)
	{
		if (sa && sb)
			ft_printf("%-11d   |   %11d\n", sa->value, sb->value);
		else if (sa && !sb)
			ft_printf("%-11d   |   %11c\n", sa->value, ' ');
		else if (!sa && sb)
			ft_printf("%-11d   |   %11d\n", ' ', sb->value);
		if (sa)
			sa = sa->next;
		if (sb)
			sb = sb->next;
	}
	ft_putstr("-----------   |   -----------\n\n");
	if (op)
		ft_strdel(&op);
	return ;
}
