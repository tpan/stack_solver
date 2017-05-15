/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:02:11 by tpan              #+#    #+#             */
/*   Updated: 2016/11/17 10:37:15 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = ft_strlen((char *)s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	trimmed = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!trimmed)
		return (trimmed);
	ft_strncpy(trimmed, &s[i], (j - i + 1));
	trimmed[j - i + 1] = '\0';
	return (trimmed);
}
