/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:03:27 by tpan              #+#    #+#             */
/*   Updated: 2016/12/20 01:50:53 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*read_fd(int fd)
{
	static t_list	*read_head;
	t_list			*tmp;

	tmp = read_head;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(&read_head, tmp);
	return (tmp);
}

static void			join(t_list *node, char const *buff, size_t size)
{
	char			*tmp;

	if (node->content == NULL)
	{
		node->content = ft_strndup(buff, size);
		return ;
	}
	tmp = node->content;
	node->content = ft_strjoin(tmp, buff);
	free((void *)buff);
}

int					get_next_line(const int fd, char **line)
{
	size_t				i;
	size_t				ret;
	char			*ptr;
	char			buf[BUFF_SIZE];
	t_list			*nd;

	i = 0;
	ret = 0;
	MEMCHECK((fd < 0 || line == NULL || read(fd, buf, 0) < 0));
	nd = read_fd(fd);
	while (!ft_strchr(nd->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		join(nd, ft_strndup(buf, ret), ret);
	if (ret < BUFF_SIZE && ft_strlen(nd->content) == 0)
	{
		ft_strclr(*line);
		return (0);
	}
	ptr = nd->content;
	i = ft_wordlength(ptr, i, '\n');
	*line = (ptr[i] == '\n') ? (ft_strndup(ptr, i)) : (ft_strdup(nd->content));
	if ((ret == 0 && ptr[i] == 0))
		ft_strclr((char*)(nd->content));
	nd->content = (ptr[i] == '\n') ? (ft_strdup(nd->content + (i + 1))) :
		(nd->content + 0);
	return (1);
}