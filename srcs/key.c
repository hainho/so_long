/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:34 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 02:51:35 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_to_tile(t_solong *sl, int x, int y)
{
	sl->map_info.map[y][x] = 'P';
	sl->map_info.map[sl->player_info.y][sl->player_info.x] = '0';
	sl->player_info.move++;
	sl->player_info.x = x;
	sl->player_info.y = y;
	ft_putstr_fd("MOVE COUNT : ", 1);
	ft_putnbr_fd(sl->player_info.move, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

static void	move_to_collection(t_solong *sl, int x, int y)
{
	sl->map_info.map[y][x] = 'P';
	sl->map_info.map[sl->player_info.y][sl->player_info.x] = '0';
	sl->map_info.c_num--;
	sl->player_info.move++;
	sl->player_info.x = x;
	sl->player_info.y = y;
	ft_putstr_fd("MOVE COUNT : ", 1);
	ft_putnbr_fd(sl->player_info.move, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

static void	move_to_exit(t_solong *sl)
{
	ft_putstr_fd("MOVE COUNT : ", 1);
	ft_putnbr_fd(sl->player_info.move, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("game clear\n", 1);
	exit_with_free(sl, 0);
	return ;
}

static void	move(t_solong *sl, int x, int y)
{
	if (sl->map_info.map[y][x] == '0')
		move_to_tile(sl, x, y);
	else if (sl->map_info.map[y][x] == 'C')
		move_to_collection(sl, x, y);
	else if (sl->map_info.map[y][x] == 'E' && sl->map_info.c_num == 0)
		move_to_exit(sl);
	return ;
}

int	key_press(int keycode, t_solong *sl)
{
	if (keycode == KEY_W && sl->player_info.y > 0)
		move(sl, sl->player_info.x, sl->player_info.y - 1);
	else if (keycode == KEY_S && sl->player_info.y < sl->map_info.c - 1)
		move(sl, sl->player_info.x, sl->player_info.y + 1);
	else if (keycode == KEY_A && sl->player_info.x > 0)
		move(sl, sl->player_info.x - 1, sl->player_info.y);
	else if (keycode == KEY_D && sl->player_info.x < sl->map_info.r - 1)
		move(sl, sl->player_info.x + 1, sl->player_info.y);
	else if (keycode == KEY_ESC)
		exit_with_free(sl, 0);
	put_img_all(sl);
	return (0);
}