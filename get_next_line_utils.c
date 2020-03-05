/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuehiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:16:46 by csuehiro          #+#    #+#             */
/*   Updated: 2020/03/02 22:05:25 by csuehiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		cont;
	int		aux;

	if (s1 == 0 || s2 == 0)
		return (0);
	cont = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0 || (s1 == 0))
		return (0);
	while (s1[cont] != '\0')
	{
		str[cont] = s1[cont];
		cont++;
	}
	aux = 0;
	while (s2[aux] != '\0')
	{
		str[cont + aux] = s2[aux];
		aux++;
	}
	str[cont + aux] = '\0';
	free((char *)s1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;
	int		cont;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	cont = 0;
	while (s1[cont] != '\0')
	{
		str[cont] = s1[cont];
		cont++;
	}
	str[cont] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			return ((char *)&s[cont]);
		cont++;
	}
	if (c == '\0')
		return ((char *)&s[cont]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	cont;

	cont = -1;
	if (s == 0)
		return (0);
	if (ft_strlen(s) >= start)
	{
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (sub == 0)
			return (0);
		while (++cont < len)
			sub[cont] = s[start + cont];
		sub[cont] = '\0';
	}
	else
	{
		sub = (char *)malloc(sizeof(char) * 1);
		if (sub == 0)
			return (0);
		sub[0] = '\0';
	}
	return (sub);
}
