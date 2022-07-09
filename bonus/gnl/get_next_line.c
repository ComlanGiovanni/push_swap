/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:31:21 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 00:04:07 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"
#include "../../lib/libft.h"

/**
 * @brief 
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return size_t 
 */
static size_t	ft_small(const char *s, unsigned int start, size_t len)
{
	if (len > ft_strlen(s + start))
		return (ft_strlen(s + start) + 1);
	return (len + 1);
}

/**
 * @brief 
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	idx;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	idx = 0;
	str = (char *)malloc(sizeof(char) * ft_small(s, start, len));
	if (str == 0)
		return (NULL);
	while (idx < (ft_small(s, start, len) - 1))
	{
		str[idx] = s[idx + start];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

/**
 * @brief 
 * 
 * @param str 
 * @param n 
 * @param line 
 * @param fd 
 * @return int 
 */
int	ft_get_line(char **str, int n, char **line, int fd)
{
	char	*tmp;
	int		idx;

	idx = 0;
	while (str[fd][idx] && str[fd][idx] != '\n')
		idx++;
	*line = ft_substr(str[fd], 0, idx);
	if (!str[fd][idx])
	{
		tmp = str[fd];
		str[fd] = NULL;
		free(tmp);
		return (0);
	}
	else
	{
		tmp = str[fd];
		str[fd] = ft_strdup((str[fd]) + idx + 1);
		free(tmp);
	}
	if (!str[fd] || !*line)
		return (-1);
	if (n || (n == 0 && str[fd] != NULL))
		return (1);
	return (-1);
}

/**
 * @brief 
 * 
 * @param fd 
 * @param str 
 * @param buff 
 * @return int 
 */
int	ft_read_line(int fd, char *str[4864], char *buff)
{
	char	*tmp;
	int		idx;

	idx = read(fd, buff, BUFFER_SIZE);
	while (idx)
	{
		tmp = str[fd];
		buff[idx] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
		if (!str[fd])
			return (-1);
		free(tmp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	return (1);
}

/**
 * @brief Get the next line object
 * 
 * @param fd 
 * @param line 
 * @return int 
 */
int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*str[4864];
	int				n;

	n = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
		|| !buff || read(fd, buff, 0) == -1)
		return (-1);
	if (!str[fd])
	{
		str[fd] = ft_strdup("");
		if (!str[fd])
			return (-1);
	}
	if (ft_read_line(fd, str, buff) == -1)
		return (-1);
	free(buff);
	return (ft_get_line(str, n, line, fd));
}

/*
size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	if (s == NULL)
		return (0);
	while (s[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*dest;

	dest = malloc(ft_strlen(s1) + 1);
	if (dest == 0)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	idx_1;
	size_t	idx_2;
	char	*dest;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	idx_1 = -1;
	idx_2 = 0;
	while (s1[++idx_1])
		dest[idx_1] = s1[idx_1];
	while (s2[idx_2])
		dest[idx_1++] = s2[idx_2++];
	dest[idx_1] = '\0';
	return (dest);
}
*/
