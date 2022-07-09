/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:32:27 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 23:30:10 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE (8)

int				get_next_line(int fd, char **line);
int				ft_get_line(char **str, int n, char **line, int fd);
int				ft_read_line(int fd, char *str[4864], char *buff);
int				ft_get_line(char **str, int n, char **line, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif