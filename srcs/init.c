/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:52 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 02:51:52 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_solong *sl)
{
	sl->map_info.c_num = 0;
	sl->map_info.p_num = 0;
	sl->map_info.e_num = 0;
	sl->player_info.move = 0;
	sl->map_info.map = NULL;
	return ;
}
