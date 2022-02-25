/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:01:05 by iha               #+#    #+#             */
/*   Updated: 2022/02/25 19:54:05 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_gnl_strlen(char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_gnl_strdup(char *s)
{
	int		len;
	char	*temp;
	char	*dst;

	len = ft_gnl_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	temp = dst;
	while (len--)
		*temp++ = *s++;
	*temp = '\0';
	return (dst);
}

char	*ft_gnl_strjoin(char *str1, char *str2)
{
	char	*join_str;
	char	*temp;
	int		len;
	int		idx;

	if (!(str1) && !(str2))
		return (NULL);
	if (!str1)
		return (ft_gnl_strdup(str2));
	if (!str2)
		return (ft_gnl_strdup(str1));
	idx = 0;
	len = ft_gnl_strlen(str1) + ft_gnl_strlen(str2);
	join_str = (char *)malloc(sizeof(char) * (len + 1));
	temp = join_str;
	if (join_str == NULL)
		return (NULL);
	while (str1[idx])
		*temp++ = str1[idx++];
	idx = 0;
	while (str2[idx])
		*temp++ = str2[idx++];
	*temp = '\0';
	return (join_str);
}

void	*ft_gnl_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dst;
	s = src;
	if (dst == src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}

size_t	ft_gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t		srcsize;

	if (dst == 0 || src == 0)
		return (0);
	srcsize = ft_gnl_strlen(src);
	if (srcsize + 1 < dstsize)
		ft_gnl_memcpy(dst, src, srcsize + 1);
	else if (dstsize != 0)
	{
		ft_gnl_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (srcsize);
}
