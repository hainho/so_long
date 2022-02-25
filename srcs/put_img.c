/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:12 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 02:51:13 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_solong *sl, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, \
		sl->img_info.img_ptr_0, x, y);
	else if (c == '1')
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, \
		sl->img_info.img_ptr_1, x, y);
	else
	{
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, \
		sl->img_info.img_ptr_0, x, y);
		if (c == 'P')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, \
			sl->img_info.img_ptr_p, x, y);
		else if (c == 'C')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, \
			sl->img_info.img_ptr_c, x, y);
		else if (c == 'E')
			mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, \
			sl->img_info.img_ptr_e, x, y);
		else
			error_exit(sl, "map valiation error at put_img");
	}
	return ;
}

static void	put_img_line(t_solong *sl, int line)
{
	char	*cur;
	int		idx;

	idx = 0;
	cur = sl->map_info.map[line];
	while (cur[idx])
	{
		put_img(sl, cur[idx], SQUARE_SIZE * idx, SQUARE_SIZE * line);
		idx++;
	}
	return ;
}

void	put_img_all(t_solong *sl)
{
	int	line;

	line = 0;
	while (sl->map_info.map[line])
		put_img_line(sl, line++);
	return ;
}
