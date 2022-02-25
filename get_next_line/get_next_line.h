/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:48:31 by iha               #+#    #+#             */
/*   Updated: 2021/07/27 13:11:13 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX      32
# endif

char	*get_next_line(int fd);
int		ft_gnl_strlen(char *str);
char	*ft_gnl_strdup(char *s);
char	*ft_gnl_strjoin(char *str1, char *str2);
void	*ft_gnl_memcpy(void *dst, void *src, size_t n);
size_t	ft_gnl_strlcpy(char *dst, char *src, size_t dstsize);

#endif
