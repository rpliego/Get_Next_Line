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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == '\0')
		return (NULL);
	return (&s[i]);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = malloc(1 * sizeof(char));
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (!str)
		return (ft_free(&left_str));
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	temp;
	unsigned int	aux;

	temp = 0;
	aux = 0;
	while (src[temp] != '\0')
		temp++;
	if (size != '\0')
	{
		while (src[aux] != '\0' && aux < (size - 1))
		{
			dest[aux] = src[aux];
			aux++;
		}
		dest[aux] = '\0';
	}
	return (temp);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	lens;
	size_t	i;
	char	*x;

	lens = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start > lens)
	{
		x = malloc(sizeof(char) * (1));
		if (!x)
			return (NULL);
		x[0] = '\0';
		return (x);
	}
	if (lens - start < len)
		len = lens - start;
	x = (char *)malloc(len + 1);
	if (!x)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(x, s, len + 1);
	return (x);
}
