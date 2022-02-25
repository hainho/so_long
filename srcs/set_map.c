/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:23 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 02:51:23 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_row(int fd)
{
	char	*row;
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	row = malloc(sizeof(char) * ft_strlen(line));
	if (row == NULL)
		return (NULL);
	if (ft_strlcpy(row, line, ft_strlen(line)) == 0)
		return (NULL);
	free(line);
	return (row);
}

static void	set_player(t_solong *sl, char *line, int count)
{
	int	idx;

	idx = 0;
	while (line[idx])
	{
		if (line[idx] == 'P')
		{
			sl->player_info.x = idx;
			sl->player_info.y = count;
			return ;
		}
		idx++;
	}
	return ;
}

static void	set_rc(t_solong *sl, char *fileName)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		error_exit(sl, "map_fileopen fail at set_rc");
	line = get_row(fd);
	if (line == NULL)
		error_exit(sl, "map_row is 0 at set_rc");
	sl->map_info.r = ft_strlen(line);
	while (line)
	{
		set_player(sl, line, count);
		free(line);
		line = get_row(fd);
		count++;
	}
	sl->map_info.c = count;
	close(fd);
	return ;
}

void	set_map(t_solong *sl, char *fileName)
{
	int	fd;
	int	idx;

	set_rc(sl, fileName);
	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		error_exit(sl, "map_fileopen fail at set_map");
	sl->map_info.map = malloc(sizeof(char*) * (sl->map_info.c + 1));
	idx = 0;
	while (idx < sl->map_info.c)
		sl->map_info.map[idx++] = get_row(fd);
	sl->map_info.map[idx] = NULL;
	close(fd);
	return ;
}
