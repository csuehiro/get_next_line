/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuehiro <csuehiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:15:55 by csuehiro          #+#    #+#             */
/*   Updated: 2020/02/19 20:57:09 by csuehiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_line(int fd, char **line, char **s)
{
	int		cont;
	char	*temp;

	cont = 0;
	while (s[fd][cont] != '\0' && s[fd][cont] != '\n')
		cont++;
	if (s[fd][cont] == '\n')
	{
		*line = ft_substr(s[fd], 0, cont);
		temp = ft_strdup(&s[fd][cont + 1]);
		free(s[fd]);
		s[fd] = temp;
//		if (s[fd][0] == '\0')
//			free(s[fd]);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
	}
}

static int	gnl_result(int fd, char **line, int i, char **s)
{
	if (i < 0)
		return (-1);
	gnl_line(fd, line, s);
	if (i > BUFFER_SIZE)
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[FD_SIZE];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			i;

	if (line == 0 || fd < 0)
		return (-1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (s[fd] == 0)
			s[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = temp;
		}
		if (buf[i - 1] == '\0')
			return (gnl_result(fd, line, BUFFER_SIZE + 1, s));
		if (ft_strchr(buf, '\n') != 0)
			break ;
	}
	return (gnl_result(fd, line, i, s));
}
