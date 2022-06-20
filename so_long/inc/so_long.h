/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:43:48 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/15 21:08:50 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*bckg;
	void	*wall;
	void	*pl_a;
	void	*pl_d;
	void	*pl_s;
	void	*pl_w;
	void	*coll;
	void	*exit;
	char	**map;
	int		to_free;
	int		collect;
	int		counter;
	int		player;
	int		door;
	int		width;
	int		height;
	int		x;
	int		y;
	int		len;
	int		lines;
	int		i;
	int		j;
	int		n;
	char	c;
}			t_mlx;

enum e_key {w = 119, a = 97, s = 115, d = 100, esc = 65307};

/* Compliance */
int		compliances(t_mlx *mlx);
int		shape_compliance(t_mlx *mlx);
int		wall_compliance(t_mlx *mlx);
int		items_compliance(t_mlx *mlx);
int		content_compliance(t_mlx *mlx);

/* Directions */
void	direction_w(t_mlx *mlx);
void	direction_a(t_mlx *mlx);
void	direction_s(t_mlx *mlx);
void	direction_d(t_mlx *mlx);

/* Display */
void	initialize_game(t_mlx *mlx);
void	update_game(t_mlx *mlx, char c);
void	initialize_player(t_mlx *mlx, int i, int j);
void	initialize_exit(t_mlx *mlx, int i, int j);

/* Destroy */
int		destroy_all(t_mlx *mlx);
void	destroy_img(t_mlx *mlx, int n);
void	image_error(t_mlx *mlx, int n);

/* Game */
int		render(void *mlx);
int		keyboard_hook(int key, t_mlx *mlx);
int		ft_game(t_mlx *mlx);
int		ft_play(t_mlx *mlx);
int		end_loop(t_mlx *mlx);

/* Initialize */
int		initialize_board(t_mlx *mlx);
int		initialize_image(t_mlx *mlx);
int		initialize_window(t_mlx *mlx);
void	*img(void *mlx_ptr, char *filename, int *width, int *height);

/* Main */
void	initialize(t_mlx *mlx);

/* Parsing */
int		parsing(t_mlx *mlx, char *str);
int		populate_map(t_mlx *mlx, int fd);
int		counting_lines(char *str);
void	free_array(t_mlx *mlx, int i);

/* Push tiles */
void	push_map(t_mlx *mlx);
void	push_wall(t_mlx *mlx);
void	push_exit(t_mlx *mlx);
void	push_coll(t_mlx *mlx);
void	push_player(t_mlx *mlx, char c);

#endif
