/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:31:02 by tpan              #+#    #+#             */
/*   Updated: 2017/05/22 13:18:39 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atol(unsigned char *str)
{
	int				is_negative;
	long				nbr;

	is_negative = 0;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		is_negative = 1;
	if ((*str == '+' || *str == '-'))
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr *= 10;
		nbr += (*str - '0');
		str++;
	}
	if (is_negative == 1)
		nbr *= -1;
	return (nbr);
}
