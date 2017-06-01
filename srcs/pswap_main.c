/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 14:58:23 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 19:16:34 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Finds the most efficient algorithm depending on our data set.
*/

static void		sort_selection(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	if (stack_len(*sa) <= 3)
		three_sort(sa, sb, tracker);
	else if (stack_len(*sa) < 10)
		bubblesque_sort(sa, sb, tracker);
	else
		sort_stacks(sa, sb, tracker);
}

/*
** Takes input and initializes the stack, parses ints as a single string
** seperated by spaces and then as individual arguments.
*/

static void		get_input(char **argv, t_swap **sa, t_tracker *tracker)
{
	char		**new_argv;

	if ((new_argv = parse_args(++argv)))
		*sa = read_input_init_stack(new_argv, tracker);
	else
		*sa = read_input_init_stack(argv, tracker);
	tracker->input_cnt = stack_len(*sa);
	if (new_argv)
		ft_tab_del(&new_argv);
}

int				main(int argc, char **argv)
{
	t_swap		*sa;
	t_swap		*sb;
	t_tracker	tracker;

	ft_bzero(&tracker, sizeof(t_tracker));
	if (argc > 1)
	{
		get_input(argv, &sa, &tracker);
		if (!check_duplicates(sa))
		{
			sb = NULL;
			if (tracker.debug)
				print_stacks(sa, sb, &tracker);
			sort_selection(&sa, &sb, &tracker);
			if (tracker.debug)
				print_logs(sa, &tracker);
		}
		free_stack(sa);
	}
	return (0);
}
