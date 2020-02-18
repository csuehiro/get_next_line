/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuehiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:16:46 by csuehiro          #+#    #+#             */
/*   Updated: 2020/02/17 22:54:30 by csuehiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*str;
	int		cont;
	int		aux;

	if (s1 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	cont = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
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
	return (str);
}

char	*ft_strcpy(char *str)
{
	int		cont;
	int		len;
	char	*aux;

	if (str == 0)
		return (0);
	cont = 0;
	len = ft_strlen(str);
	aux = (char *)malloc(sizeof(char) * (len + 1));
	if (aux == 0)
		return (0);
	while (cont < len)
	{
		aux[cont] = str[cont];
		cont++;
	}
	aux[cont] = '\0';
	return (aux);
}

char	*ft_strchr(char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			return (&s[cont]);
		cont++;
	}
	if (c == '\0')
		return (&s[cont]);
	return (0);
}
