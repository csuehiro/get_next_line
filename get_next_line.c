/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuehiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:15:55 by csuehiro          #+#    #+#             */
/*   Updated: 2020/02/17 23:53:59 by csuehiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_eof(int fd, char **line, char **s)
{
	int	cont;

	cont = 0;
	while (s[fd][cont] != '\0')
	{
		*line[cont] = s[fd][cont];
		cont++;
	}
}

static int	gnl_result(int fd, char **line, int i, char **s)
{
	if (i < 0) //erro na leitura
		return (-1);
	if (i > BUFFER_SIZE) //EOF
	{
		//tratar linha
		return (0);
	}
	//tratar linha
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[FD_SIZE];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			i;

	if (line == 0 || fd < 0) //se não veio um endereço para guardar o line ou fd negativo é erro
		return (-1);
	while (i = read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[i] = '\0';
		if (s[fd] == 0)
			s[fd] = ft_strcpy(buf);
		else
		{
			temp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = temp;
		}
		if (buf[i - 1] == '\0')
			return (gnl_result(fd, line, BUFFER_SIZE + 1, s);
		if (ft_strchr(buf, '\n') != 0)
			break ;
	}
	return (gnl_result(fd, line, i, s));
}
