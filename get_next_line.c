/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:21:43 by rpliego           #+#    #+#             */
/*   Updated: 2023/07/08 03:08:17 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char **clean)
{
	free(*clean);
	*clean = NULL;
	return (NULL);
}

char	*ft_clean_stash(char *stash)
{
	char	*new_stash;
	char	*ptr;
	int		len;

	ptr = ft_strchr(stash, '\n');
	if (!ptr)
	{
		new_stash = NULL;
		return (ft_free(&stash));
	}
	len = (ptr - stash) + 1;
	if (!stash[len])
		return (ft_free(&stash));
	new_stash = ft_substr(stash, len, ft_strlen(stash) - len);
	ft_free(&stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*ft_line_make(char *stash)
{
	char	*aux;
	int		len;
	char	*line;

	aux = ft_strchr(stash, '\n');
	len = (aux - stash) + 1;
	line = ft_substr(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	int		bytes;
	char	*buff;

	bytes = 69;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(&stash));
	buff[0] = '\0';
	while (bytes > 0 && !ft_strchr(buff, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes > 0)
		{
			buff[bytes] = '\0';
			stash = ft_strjoin(stash, buff);
		}
	}
	free(buff);
	if (bytes == -1)
		return (ft_free(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line_make(stash);
	if (!line)
		return (ft_free(&stash));
	stash = ft_clean_stash(stash);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

//  int	main(void)
//  {
//  	char	*line;
//  	int		fd1;

//  	fd1 = open("test/test.txt", O_RDONLY);

//  	line = get_next_line(fd1);
//  	printf("%s", line);
// 	free(line);
//  	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);

//  	close(fd1);
//  	return (0);
// }
