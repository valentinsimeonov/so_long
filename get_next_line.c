/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:24:34 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/11 17:29:52 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>



char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			read_count;
	char		*line;

	line = (char *)ft_calloc(1, sizeof(char));
	while (!ft_strchr(buf, '\n'))
	{
		if (*buf)
			line = ft_strjoin(line, buf);
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count <= 0 && !(*line))
		{
			free(line);
			return (NULL);
		}
		buf[read_count] = '\0';
		if (!ft_strchr(buf, '\n') && read_count < BUFFER_SIZE)
		{
			line = ft_strjoin(line, buf);
			ft_bzero(buf, 1);
			return (line);
		}
	}
	line = move_in_line(line, buf);
	return (line);
}

char	*move_in_line(char *line, char *buf)
{
	char	*pointer;
	int		first_line_len;
	int		second_line_len;
	char	*temp;
	int		len_buf;

	len_buf = ft_strlen(buf);
	pointer = ft_strchr(buf, '\n');
	first_line_len = len_buf - ft_strlen(pointer + 1);
	second_line_len = len_buf - first_line_len;
	temp = ft_substr(buf, 0, first_line_len);
	line = ft_strjoin(line, temp);
	buf = ft_memmove(buf, &buf[first_line_len], second_line_len);
	ft_bzero(&buf[second_line_len], first_line_len);
	free(temp);
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*(str + i) == c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + len + 1);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < (int)n)
	{
		*(p + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, count * size);
	return (p);
}



///////////////////////////////////////////////////////////////////


size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < (int)n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
		{
			*(d + len) = *(s + len);
		}
	}
	else
	{
		while (len-- > 0)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, lens1);
	ft_memcpy(str + lens1, s2, lens2);
	*(str + lens1 + lens2) = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	lenstr;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	lenstr = ft_strlen(s);
	if (start >= lenstr)
		return (p);
	while (i < len)
	{
		*(p + i) = *(s + start);
		i++;
		start++;
	}
	*(p + i) = '\0';
	return (p);
}
