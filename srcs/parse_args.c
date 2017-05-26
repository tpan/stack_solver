/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:26:13 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 21:46:24 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char		**split_args(char **argv, int index, int arg_len)
{
	char	**new_argv; 
	char	**tmp;
	int		i;

	new_argv = ft_strtok(argv[index], " ");
	i = 0;
	while (i < arg_len && argv[i])
	{
		if (i != index)
		{
			tmp = ft_tab_add_one(new_argv, argv[i]);
			free(new_argv);
			new_argv = tmp;
		}
		i++;
	}
	return (new_argv);
}

char			**parse_args(char **argv)
{
	int		i;
	int		arg_len;

	arg_len = ft_tab_len(argv);
	i = 0;
	while (argv && argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			return (split_args(argv, i , arg_len));
		i++;
	}
	return (NULL);
}
