/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:21:18 by bschoeff          #+#    #+#             */
/*   Updated: 2022/07/12 11:57:06 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/* Main */
int		populate(t_node **stacka, char *str);
void	about_ops(t_list **ops);

/* Utils */
void	release(t_node **lst);
void	display(t_list	**lst);
void	display_lst(t_node	**lst);
int		compliance_arguments(char *s);
int		compliance_duplicates(t_node **lst);

/* Actions */
void	swap(t_node **lst, t_list **ops, char *word);
void	push(t_node **dst, t_node **src, t_list **ops, char *word);
void	rotate(t_node **lst, t_list **ops, char *word);
void	rev_rotate(t_node **lst, t_list **ops, char *word);

/* Sort */
void	sort(t_node **stacka, t_node **stackb, t_list **ops);
int		already_sorted(t_node **lst);
void	position(t_node **lst);
void	index_list(t_node **stacka);

/* Small stack */
void	three_stack(t_node **stacka, t_list **ops);
void	case_alpha(t_node **stacka, t_list **ops, t_node *tmp, t_node *tmp_n);
void	case_beta(t_node **stacka, t_list **ops, t_node *tmp_n);

/* Big stack */
void	big_stack(t_node **stacka, t_node **stackb, t_list **ops);
void	proceed(t_node **stacka, t_node **stackb, t_list **ops);
void	execute_b(t_node **stackb, t_node *tmp, t_list **ops);
void	execute_a(t_node **stacka, t_node *tmp, t_list **ops);
void	finalize(t_node **stacka, t_list **ops);

/* Big stack utils */
void	tg_position(t_node **stack, t_node **stackb);
void	costs(t_node **stacka, t_node **stackb);
void	select_node(t_node **stackb, int *grand_cost);

/* Sanitize */
void	sanitize(t_list **ops);
void	sanitize_rotate(t_list	**ops);
void	sanitize_rev_rotate(t_list **ops);

#endif
