/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:10:26 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 16:56:05 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Parse args and ensure there is no mixing of ints and letters in an arg. 
** Ends the program and exits with an error message if found. The arg should
** never start with a char.
*/

static int			validate_input(char *input, t_swap *sa)
{
	int		i;

	if (ft_isalpha(*input))
		invalid_input_error(sa);
	i = 0;
	if (ft_isdigit(input[0]))
		while (input[++i])
			if (!ft_isalpha(input[i]))
				invalid_input_error(sa);
	i = 0;
	if (input[0] == '-' && ft_isalpha(input[1]))
		while (input[++i])
			if (!ft_isalpha(input[i]))
				invalid_input_error(sa);
	i = 0;
	if (input[0] == '-' && ft_isdigit(input[1]))
		while (input[++i])
			if (!ft_isdigit(input[i]))
				invalid_input_error(sa);
	return (1);
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
			if (arg[i] != 'v')
				return (0);
		if (ft_isdigit(arg[i]))
			return (0);
		if (ft_strchr(arg, 'v'))
			tracker->debug = 1;
		return (1);
	}
	return (0);
}

int			check_duplicates(t_swap *stack)
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
	return (0);
}

/*
** Creates a new t_swap item from the current arg.
*/

static t_swap		*create_list_element(char **argv)
{
	long		tmp;
	t_swap		*sa;

	sa = (t_swap *)malloc(sizeof(t_swap));
	ft_bzero(sa, sizeof(t_swap));
	tmp = ft_atol(*argv);
	if (tmp > INT_MAX || tmp < INT_MIN)
		invalid_input_error(sa);
	sa->value = tmp;
	return (sa);
}

/*
** Reads the list of arguments, checks they are valid and saves them in a
** linked list, which represents our stack (closest analog in my mind).
*/

t_swap				*read_input_init_stack(char **argv, t_tracker *tracker)
{
	t_swap		*sa;
	t_swap		*element;

	sa = NULL;
	while (argv && *argv && validate_input(*argv, sa) &&
												option_flag(*argv, tracker))
		argv++;
	if (!argv || !*argv)
		return (NULL);
	sa = create_list_element(argv);
	while (*(++argv))
		if (!option_flag(*argv, tracker) && validate_input(*argv, sa))
		{
			element = create_list_element(argv);
			stack_append(&sa, element);
		}
		return (sa);
}
