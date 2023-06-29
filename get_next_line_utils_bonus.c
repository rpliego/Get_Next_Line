/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:32:45 by rpliego           #+#    #+#             */
/*   Updated: 2023/06/29 16:40:06 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *stash, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(buff)) + 1));
	if (!str)
		return (ft_free(&stash));
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			str[i] = stash[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(stash) + ft_strlen(buff)] = '\0';
	free(stash);
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
