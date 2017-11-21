/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:17:55 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/29 04:08:52 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_create_lst(t_line **lst, int fd, char *buff, int i)
{
	t_line	*new;
	t_line	*tmp;
	int		j;

	j = ft_strchrint(buff, '\n');
	if (i == 1)
		j = -1;
	tmp = *lst;
	if (buff[j + 1] == '\0')
		return (0);
	if (!(new = (t_line*)malloc(sizeof(t_line))))
		return (-1);
	new->fd = fd;
	new->i = 0;
	new->next = NULL;
	new->rest = ft_strdup(&buff[j + 1]);
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

int				ft_put_rest_in_line(t_line **lst, char ***line, int fd)
{
	t_line	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd && tmp->rest != NULL)
		{
			while (tmp->rest[tmp->i] && tmp->rest[tmp->i] != '\n')
			{
				**line = ft_strjoinchar(**line, tmp->rest[tmp->i]);
				tmp->i++;
			}
			if (tmp->rest[tmp->i] == '\n')
			{
				**line = ft_strjoinchar(**line, '\0');
				tmp->i++;
				return (1);
			}
			else
				ft_strdel(&tmp->rest);
		}
		tmp = tmp->next;
	}
	return (0);
}

int				ft_put_buff_in_line(char ***line, char *buff, int index_buff,
	int i)
{
	int j;

	j = 0;
	if (index_buff != 0 && i == 0)
	{
		if (buff[j] == '\n')
		{
			**line = ft_strjoinchar(**line, '\0');
			return (1);
		}
		else if (index_buff != 0 && ft_strchrint(buff, '\n') == -1)
		{
			while (buff[j++])
				**line = ft_strjoinchar(**line, buff[j - 1]);
			j = 0;
			return (0);
		}
	}
	if (index_buff != 0 && i == 0)
		while (buff[j++] != '\n' && buff[j] != '\0')
			**line = ft_strjoinchar(**line, buff[j - 1]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				index_buff;
	int				i;
	char			buff[BUFF_SIZE + 1];
	static t_line	*lst;

	if (fd < 0 || !(line))
		return (-1);
	if ((index_buff = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	buff[index_buff] = '\0';
	*line = NULL;
	i = ft_put_rest_in_line(&lst, &line, fd);
	while (ft_put_buff_in_line(&line, buff, index_buff, i) == 0)
	{
		index_buff = read(fd, buff, BUFF_SIZE);
		buff[index_buff] = '\0';
	}
	if (index_buff != 0)
		ft_create_lst(&lst, fd, buff, i);
	if (index_buff == 0 && i == 0 && *line == NULL)
		return (0);
	return (*line != NULL ? 1 : -1);
}
