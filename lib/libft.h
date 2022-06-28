/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:32:22 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:42:56 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_count_str(char *str, char c);
int		ft_allocate_memory(char **strs, char *str, char c);
void	ft_fill_strs(char **strs, char *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen_2(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_free_tab(char **tab);
int		ft_strcmp(char *s1, char *s2);

#endif
