/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:39 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 02:58:38 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	line_valid(t_solong *sl, t_map *map_info, char *line)
{
	int	idx;

	idx = 0;
	while (line[idx])
	{
		if (line[idx] == '0' || line[idx] == '1')
		{
		}
		else if (line[idx] == 'P')
			map_info->p_num++;		
		else if (line[idx] == 'C')
			map_info->c_num++;		
		else if (line[idx] == 'E')
			map_info->e_num++;
		else
			error_exit(sl, "map_validation error at line_valid");
		idx++;
	}
	if (map_info->r != idx)
		error_exit(sl, "map file error at line_valid");
	return ;
}

static void	wall_valid(t_solong *sl, t_map *map_info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map_info->r)
	{
		if (map_info->map[y][x] != '1' || \
		map_info->map[y + map_info->c - 1][x++] != '1')
			error_exit(sl, "wall_valid error at wall_valid");
	}
	x = 0;
	while (y < map_info->c)
	{
		if (map_info->map[y][x] != '1' || \
		map_info->map[y++][x + map_info->r - 1] != '1')
			error_exit(sl, "wall_valid error at wall_valid");
	}
	return ;
}

void	map_valid(t_solong *sl, t_map *map_info)
{
	int	idx;

	idx = 0;
	while (map_info->map[idx])
		line_valid(sl, map_info, map_info->map[idx++]);
	if (map_info->c != idx || map_info->p_num != 1 || \
	map_info->e_num != 1 || map_info->c_num <= 0)
		error_exit(sl, "map file error at map_valid");
	wall_valid(sl, map_info);
	return ;
}

void 	file_valid(t_solong *sl, char *fileName)
{
	char	*temp;

	temp = ft_strrchr(fileName, '.');
	if (ft_strncmp(temp, ".ber", 4) != 0)
		error_exit(sl, "map file name error at file_valid");
	return ;
}
