/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:20:35 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:04:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_strchrs(const char *s, int c)
{
	if (!s)
		return (NULL);
	return (ft_strchr(s, c));
}

char	*ft_strsubchr(const char *s, char c)
{
	char	*ptr;

	if (!(ptr = ft_strchrs(s, c)))
		return (NULL);
	return (ft_strsub(s, 0, ptr - s));
}


static t_file	*new_file(const int fd)
{
	t_file *new;

	if ((new = (t_file *)ft_memalloc(sizeof(t_file))))
	{
		new->fd = fd;
		new->str = NULL;
	}
	return (new);
}

static t_file	*get_file(const int fd, t_file **head)
{
	t_file *lst;

	if (!(*head))
		return (*head = new_file(fd));
	lst = *head;
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	return ((lst->fd == fd) ? lst : (lst->next = new_file(fd)));
}

static int		str_divide(char **str, char **line)
{
	char	*new;
	char	*div;

	if (!(*line = ft_strsubchr(*str, '\n')))
		return (-1);
	div = ft_strchrs(*str, '\n');
	div++;
	if (!ft_strlen(div))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup(div);
	free(*str);
	*str = new;
	return ((new) ? 1 : -1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*head = NULL;
	t_file			*f;
	char			buff[BUFF_SIZE + 1];
	ssize_t			size;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || !(f = get_file(fd, &head)))
		return (-1);
	while (!ft_strchrs(f->str, '\n'))
	{
		if (!(size = read(fd, buff, BUFF_SIZE)))
		{
			if (!(*line = f->str))
				return (0);
			f->str = NULL;
			return (1);
		}
		buff[size] = '\0';
		tmp = f->str;
		f->str = ft_strjoin(f->str, buff);
		free(tmp);
		if (!f->str)
			return (-1);
	}
	return (str_divide(&(f->str), line));
}*/

static t_list	*get_current_fd(t_list **st, const int fd)
{
	t_list *tmp;

	tmp = *st;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(st, tmp);
	tmp = *st;
	return (tmp);
}

static int		ft_strcpy_ch(char **line, char *buf, char c)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == c)
			break ;
		i++;
	}
	*line = (char*)malloc(sizeof(char) * (i + 1));
	(*line)[i] = '\0';
	*line = ft_strncpy(*line, buf, i);
	return (i);
}

static void		ft_next_n_char(char **str, unsigned int n)
{
	char *tmp;

	tmp = *str;
	*str = ft_strdup(tmp + n);
	ft_strdel(&tmp);
}

static char		*ft_strjoin_customed(char *str, char *buf)
{
	char	*str_return;
	int		len;
	int		i;

	if (str && buf)
	{
		str_return = ft_strnew(ft_strlen(str) + ft_strlen(buf));
		i = 0;
		while (str[i] != '\0')
		{
			str_return[i] = str[i];
			i++;
		}
		len = 0;
		while (buf[len] != '\0')
		{
			str_return[i + len] = buf[len];
			len++;
		}
		str_return[i + len] = '\0';
		free(str);
		return (str_return);
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static t_list	*st;
	char			buf[BUFF_SIZE + 1];
	t_list			*cur;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	cur = get_current_fd(&st, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		cur->content = ft_strjoin_customed(cur->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(cur->content))
		return (0);
	ret = ft_strcpy_ch(line, cur->content, '\n');
	if (ret < (int)ft_strlen(cur->content))
		ft_next_n_char((char**)&cur->content, ret + 1);
	else
		ft_strclr(cur->content);
	return (1);
}
