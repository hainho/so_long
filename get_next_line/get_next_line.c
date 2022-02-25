/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:48:15 by iha               #+#    #+#             */
/*   Updated: 2021/07/27 13:08:22 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *str)
{
	int	cur;

	cur = 0;
	if (str == NULL)
		return (-1);
	while (str[cur])
	{
		if (str[cur] == '\n')
			return (cur);
		cur++;
	}
	return (-1);
}

int	read_buf(int fd, char **backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		idx;

	if (is_newline(backup[fd]) != -1)
		return (1);
	idx = read(fd, buf, BUFFER_SIZE);
	while (idx > 0)
	{
		buf[idx] = '\0';
		temp = backup[fd];
		backup[fd] = ft_gnl_strjoin(backup[fd], buf);
		free(temp);
		if (is_newline(buf) != -1)
			return (1);
		idx = -1;
		while (++idx <= BUFFER_SIZE)
			buf[idx] = '\0';
		idx = read(fd, buf, BUFFER_SIZE);
	}
	return (0);
}

char	*line_split(int fd, char **backup)
{
	int		idx;
	char	*next_line;
	char	*temp;

	idx = is_newline(backup[fd]) + 1;
	next_line = malloc(sizeof(char) * (idx + 1));
	if (next_line == NULL)
		return (NULL);
	temp = malloc(sizeof(char) * (ft_gnl_strlen(backup[fd]) - idx + 1));
	if (temp == NULL)
		return (NULL);
	ft_gnl_strlcpy(next_line, backup[fd], idx + 1);
	ft_gnl_strlcpy(temp, backup[fd] + idx, ft_gnl_strlen(backup[fd]) - idx + 1);
	free(backup[fd]);
	backup[fd] = temp;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*next_line;
	int			flag;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	flag = read_buf(fd, backup);
	if (ft_gnl_strlen(backup[fd]) == 0)
		return (NULL);
	if (is_newline(backup[fd]) == ft_gnl_strlen(backup[fd]) - 1)
		flag = 0;
	if (flag == 0)
	{
		next_line = ft_gnl_strdup(backup[fd]);
		free(backup[fd]);
		backup[fd] = NULL;
		if (next_line == NULL)
			return (NULL);
	}
	else
		next_line = line_split(fd, backup);
	if (next_line == NULL)
		return (NULL);
	return (next_line);
}
