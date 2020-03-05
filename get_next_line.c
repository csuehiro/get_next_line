/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuehiro <csuehiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:15:55 by csuehiro          #+#    #+#             */
/*   Updated: 2020/03/02 22:26:26 by csuehiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_line(int fd, char **line, char **s, int cont)
{
	char	*temp;

	*line = ft_substr(s[fd], 0, cont);
	temp = ft_strdup(&s[fd][cont + 1]);
	free(s[fd]);
	s[fd] = temp;
}

static int	gnl_eol(int fd, char **line, char **s)
{
	int i;

	i = 0;
	while (s[fd][i] != '\0')
	{
		if (s[fd][i] == '\n')
		{
			gnl_line(fd, line, s, i);
			return (i);
		}
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[OPEN_MAX];
	char		buf[ARG_MAX];
	int			i;

	if (line == 0 || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	if (s[fd] != 0)
	{
		if (gnl_eol(fd, line, s) != -1)
			return (1);
	}
	else
		s[fd] = ft_strdup("");
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		s[fd] = s[fd] == 0 ? ft_strdup(buf) : ft_strjoin(s[fd], buf);
		if (s[fd] == 0)
			return (-1);
		if (gnl_eol(fd, line, s) != -1)
			return (1);
	}
	*line = i < 0 ? 0 : s[fd];
	s[fd] = 0;
	return (i);
}
