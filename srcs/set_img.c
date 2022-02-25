/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:17 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 02:51:18 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_win(t_solong *sl)
{
	sl->mlx_ptr = mlx_init();
	if (sl->mlx_ptr == NULL)
		error_exit(sl, "mlx_init fail at set_win");
	sl->win_ptr = mlx_new_window(sl->mlx_ptr, sl->map_info.r * SQUARE_SIZE, \
	sl->map_info.c * SQUARE_SIZE, "so_long");
	if (sl->win_ptr == NULL)
		error_exit(sl, "mlx_new_window fail at set_win");
	return ;
}

void	set_img(t_solong *sl)
{
	int	w;
	int	h;

	sl->img_info.img_ptr_c = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"./image/candy.xpm", &w, &h);
	sl->img_info.img_ptr_p = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"./image/pum.xpm", &w, &h);
	sl->img_info.img_ptr_e = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"./image/exit.xpm", &w, &h);
	sl->img_info.img_ptr_0 = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"./image/tile.xpm", &w, &h);
	sl->img_info.img_ptr_1 = mlx_xpm_file_to_image(sl->mlx_ptr, \
	"./image/wall.xpm", &w, &h);
	if (sl->img_info.img_ptr_c == NULL || sl->img_info.img_ptr_e == NULL || \
	sl->img_info.img_ptr_p == NULL || sl->img_info.img_ptr_0 == NULL || \
	sl->img_info.img_ptr_1 == NULL)
		error_exit(sl, "mlx_xpm_file_to_image fail at set_img");
	return ;
}
