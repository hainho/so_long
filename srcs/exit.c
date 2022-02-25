/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:50:30 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 04:34:56 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_solong *sl)
{
	int	idx;

	if (sl->map_info.map == NULL)
		return ;
	idx = 0;
	while (sl->map_info.map[idx])
		free(sl->map_info.map[idx++]);
	free(sl->map_info.map);
	return ;
}

void	exit_with_free(t_solong *sl, int exitCode)
{
	free_map(sl);
	if (sl->win_ptr != NULL)
		mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
	exit(exitCode);
	return ;
}

int	exit_key(t_solong *sl)
{
	exit_with_free(sl, 0);
	return (0);
}
