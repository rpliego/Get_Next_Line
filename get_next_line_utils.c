/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:23:01 by rpliego           #+#    #+#             */
/*   Updated: 2023/05/26 13:23:04 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *c)
{
	int	aux;

	aux = 0;
	while (c[aux] != '\0')
		aux++;
	return (aux);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*out;
	size_t		p;
	size_t		i;
	size_t		lens1;
	size_t		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	out = (char *)malloc(lens1 + lens2 + 1);
	if (!out)
		return (NULL);
	i = 0;
	p = 0;
	while (i < lens1)
	{
		out[i] = ((char *)s1)[i];
		i++;
	}
	while (p < lens2)
	{
		out[i + p] = ((char *)s2)[p];
		p++;
	}
	out[i + p] = '\0';
	return (out);
}
