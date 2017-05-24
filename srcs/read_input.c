/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:10:26 by tpan              #+#    #+#             */
/*   Updated: 2017/05/24 12:49:32 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Parse args and check that ints are within range (less than max and more than min)
*/

static int			validate_input(char *arg)
{
	int		i;
	char	*arg_begin;

	if (!arg)
		return (0);
	arg_begin = arg;
	if (*arg == '-' || *arg == '+')
		arg++;
	i = 0;
	while (ft_isdigit(arg[i]))
		i++;
	if (i > 0 && arg[i] == '\0' && i < 9)
		return (1);
	else if ((i == 10) && (ft_atol(arg_begin) <= INT_MAX) &&
			(ft_atol(arg_begin) >= INT_MIN))
				return (1);
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
}

/*
** Checks input to find option flags and turns them on accordingly.
*/

static int			option_flag(char *arg, t_tracker *tracker)
{
	int		i;

	i = 0;
	if (arg && arg[i] == '-')
	{
		while (ft_isalpha(arg[i++]))
			if (arg[i] != 'v' && arg[i] != 'c')
				return (0);
		if (ft_isdigit(arg[i]))
			return (0);
		if (ft_strchr(arg, 'v'))
			tracker->debug = 1;
		if (ft_strchr(arg, 'c'))
			tracker->color = 1;
		return (1);
	}
	return (0);
}

int		check_duplicates(t_swap *stack)
{
	t_swap		*cmp_stack;

	cmp_stack = stack;
	while (cmp_stack)
	{
		stack = cmp_stack->next;
		while (stack)
		{
			if (cmp_stack->value == stack->value)
			{
				ft_putstr("Error\n");
				return (1);
			}
			stack = stack->next;
		}
		cmp_stack = cmp_stack->next;
	}
}

t_swap		*read_input_init_stack(char **argv, t_tracker *tracker)
{
	t_swap		*sa;
	t_swap		*item;

	while (option_flag(*argv, tracker))
		(++argv);
	if (!validate_input(*argv))
		return (NULL);
	sa = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(sa, sizeof(t_swap));
	sa->value = ft_atoi(*argv);
	while (++*argv)
	{
		if (option_flag(*argv, tracker))
			;
		else if (!validate_input(*argv))
			return (NULL);
		else
		{
			item = (t_swap *)malloc(sizeof(t_swap));
			ft_bzero(item, sizeof(t_swap));
			item->value = ft_atoi(*argv);
			stack_append(&sa, item);
		}
	}
	tracker->counter = stack_len(sa);
	return (sa);
}
