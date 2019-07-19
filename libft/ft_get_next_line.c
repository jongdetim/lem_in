/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 16:28:07 by tide-jon       #+#    #+#                */
/*   Updated: 2019/04/16 18:08:32 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl_list	*lstfind_or_addnew(const int fd, t_gnl_list **list)
{
	t_gnl_list			*current;

	current = *list;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = (t_gnl_list*)malloc(sizeof(t_gnl_list));
	if (!current)
		return (NULL);
	else
	{
		current->fd = fd;
		current->content = ft_strnew(1);
		if (!current->content)
			return (NULL);
	}
	if (*list != NULL)
		current->next = *list;
	else
		current->next = NULL;
	*list = current;
	return (current);
}

static int			reader(t_gnl_list **current, const int fd)
{
	char				buf[BUFF_SIZE + 1];
	int					chars_read;
	char				*temp;

	chars_read = read(fd, buf, BUFF_SIZE);
	if (chars_read == -1)
		return (-1);
	if (chars_read == 0)
		return (0);
	buf[chars_read] = '\0';
	temp = (*current)->content;
	(*current)->content = ft_strjoin((*current)->content, buf);
	free(temp);
	if ((*current)->content == NULL)
		return (-1);
	return (1);
}

static int			cropnpushline(t_gnl_list **current, char **line)
{
	char		*temp;

	temp = (*current)->content;
	(*current)->content = ft_strdup(ft_strchr((const char*)(*current)->content,
																	'\n') + 1);
	if ((*current)->content == NULL)
	{
		free(temp);
		return (-1);
	}
	*line = ft_strsub(temp, 0, ft_strlen(temp) - ft_strlen((*current)->content)
																		- 1);
	free(temp);
	if (*line == NULL)
		return (-1);
	return (1);
}

static int			pushfinalline(t_gnl_list **current, char **line)
{
	*line = ft_strdup((const char*)(*current)->content);
	if (*line == NULL)
		return (-1);
	ft_strclr((*current)->content);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*list;
	t_gnl_list			*current;
	int					ret;

	if (fd < 0)
		return (-1);
	current = lstfind_or_addnew(fd, &list);
	if (current == NULL)
		return (-1);
	while (ft_strchr((const char*)current->content, '\n') == NULL)
	{
		ret = reader(&current, fd);
		if (ret == -1)
			return (-1);
		if (ret == 0)
		{
			if (ft_strlen(current->content) < 1)
				return (0);
			return (pushfinalline(&current, line));
		}
	}
	return (cropnpushline(&current, line));
}
