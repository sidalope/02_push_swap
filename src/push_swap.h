/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:24:26 by abisani           #+#    #+#             */
/*   Updated: 2025/11/01 14:12:19 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list_node
{
	int					content;
	size_t				rank;
	struct s_list_node	*next;
	struct s_list_node	*prev;
}						t_list_node;

typedef struct s_stacks
{
	t_list_node			*a;
	t_list_node			*b;
	t_list_node			*list_sizes_min;
	t_list_node			*list_sizes_mid;
	t_list_node			*list_sizes_max;
}						t_stacks;

int			ft_printf(const char *format, ...);

t_list_node	*ft_lstnew(int content);
void		ft_lstadd_front(t_list_node **lst, t_list_node *new);
int			ft_lstsize(t_list_node *lst, size_t init_size, t_list_node *head);
void		ft_lstpop(t_list_node **lst);
void		ft_lstclear(t_list_node **current, t_list_node *head);
void		ft_lstiter(t_list_node *current, t_list_node *head, void (*f)(int));

int			push(t_list_node **src, t_list_node **dest);
int			swap(t_list_node **lst);
int			rotate(t_list_node **lst);
int			rrotate(t_list_node **lst);
void		del(t_list_node *node);
void		print_lst_content(t_list_node *current, t_list_node *head);
void		print_lst_ranks(t_list_node *current, t_list_node *head);
void		print_lst_sizes(t_stacks *stacks);
int			is_sorted(t_list_node *lst);

int			init(int argc, char *argv[], t_stacks *stacks);
int			check_and_rank(t_list_node *lst, t_list_node *head);
void		msort(t_stacks *stacks, size_t len);

int			ft_atoi(char *str);
int			ft_isnumber(char *str);
void		ps_error(void);
void		print_ranks(t_list_node *lst);
void		print_lists(t_stacks *stacks);

#endif