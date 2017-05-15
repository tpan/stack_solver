/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:02:45 by tpan              #+#    #+#             */
/*   Updated: 2017/03/20 20:02:06 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordlength(char *str, char delimiter)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != delimiter)
		i++;
	return (i);
}