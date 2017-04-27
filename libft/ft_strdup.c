/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:51:12 by tpan              #+#    #+#             */
/*   Updated: 2016/11/02 19:59:11 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str = malloc(len + 1);
	if (str)
	{
		p = str;
		while (*s1)
			*p++ = *s1++;
		*p = '\0';
		return (str);
	}
	return (NULL);
}
