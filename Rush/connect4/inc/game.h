/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:39:04 by anclarma          #+#    #+#             */
/*   Updated: 2022/06/12 15:04:55 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# ifndef LEVEL_AI
#  define LEVEL_AI	1
# endif

# include "connect4.h"
# include "struct.h"

int		game(t_game *g);
int		eval_all(t_game *grid);
int		eval(t_game *g, t_pos *p);
int		attempt(t_game *g, int columns, int id);
void	print_winer(int id);

int		ai_turn(t_game *g);
int		player_turn(t_game *g);

#endif
