/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:43:02 by oespion           #+#    #+#             */
/*   Updated: 2018/08/28 15:56:41 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_n(char *str)
{
	int	r;

	r = 0;
	while (str[r])
	{
		if (str[r] == '\n')
			return (r + 1);
		r++;
	}
	return (-1);
}

int		ft_strleft(t_struct *lst, char **line)
{
	int		r;
	char	*tmp;

	r = 0;
	if (!lst->str)
		return (0);
	while (lst->str[r])
	{
		if (lst->str[r] == '\n')
		{
			*line = ft_memmove(*line, lst->str, find_n(lst->str) - 1);
			tmp = ft_strdup(lst->str);
			ft_strdel(&lst->str);
			lst->str = ft_strsub(tmp, find_n(tmp),
				ft_strlen(tmp) - find_n(tmp));
			ft_strdel(&tmp);
			return (1);
		}
		r++;
	}
	ft_strdel(line);
	*line = lst->str;
	lst->str = NULL;
	return (0);
}

int		ft_read(t_struct *lst, char **line, const int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		i;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (find_n(buff) == -1)
			*line = ft_strfjoin(*line, buff);
		else
		{
			i = 0;
			*line = ft_strfjoin(*line, buff);
			lst->str = ft_strsub(buff, find_n(buff), BUFF_SIZE - find_n(buff));
			while ((*line)[i] != '\n')
				i++;
			(*line)[i] = '\0';
			return (1);
		}
	}
	return (ret == -1) ? -1 : 0;
}

int		get_next_line(const int fd, char **line)
{
	static t_struct	lst[FOPEN_MAX];
	int				ruff;

	if (!line || fd < 0 || fd > FOPEN_MAX)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (ft_strleft(&lst[fd], line) == 1)
		return (1);
	ruff = ft_read(&lst[fd], line, fd);
	if (ruff == -1)
		return (-1);
	if ((*line)[0] != '\0' || ruff == 1)
		return (1);
	return (0);
}
