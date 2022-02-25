/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:02 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 03:00:27 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	sl;

	if (argc != 2)
		return (-1);
	init(&sl);
	file_valid(&sl, argv[1]);
	set_map(&sl, argv[1]);
	map_valid(&sl, &(sl.map_info));
	set_win(&sl);
	set_img(&sl);
	put_img_all(&sl);
	ft_putstr_fd("game start\n", 1);
	mlx_hook(sl.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &sl);
	mlx_hook(sl.win_ptr, X_EVENT_KEY_EXIT, 0, &exit_key, &sl);
	mlx_loop(sl.mlx_ptr);
	return (0);
}
