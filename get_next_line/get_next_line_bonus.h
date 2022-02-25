/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:00:50 by iha               #+#    #+#             */
/*   Updated: 2022/02/25 19:56:23 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
