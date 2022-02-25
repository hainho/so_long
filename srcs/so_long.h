/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 02:51:29 by iha               #+#    #+#             */
/*   Updated: 2022/02/26 03:03:10 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SQUARE_SIZE 32
# define MALLOC_SIZE 2

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx_opengl/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
	int		r;
	int		c;
	int		p_num;
	int		c_num;
	int		e_num;
	char	**map;
}	t_map;

typedef struct s_img
{
	void	*img_ptr_p;
	void	*img_ptr_c;
	void	*img_ptr_e;
	void	*img_ptr_1;
	void	*img_ptr_0;
}	t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		move;
}	t_player;

typedef struct s_solong
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map_info;
	t_img		img_info;
	t_player	player_info;
}	t_solong;

void	map_valid(t_solong *sl, t_map *map_info);
void 	file_valid(t_solong *sl, char *fileName);
void	set_map(t_solong *sl, char *fileName);
void	set_win(t_solong *sl);
void	set_img(t_solong *sl);
void	put_img_all(t_solong *sl);
int		error(char *msg);
void	init(t_solong *sl);
int		key_press(int keycode, t_solong *sl);
void	exit_with_free(t_solong *sl, int exitCode);
void	error_exit(t_solong *sl, char *msg);
int		exit_key(t_solong *sl);

#endif
