/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:24:26 by abisani           #+#    #+#             */
/*   Updated: 2025/11/13 20:58:40 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list_node
{
	void				*content;
	int					rank;
	struct s_list_node	*next;
	struct s_list_node	*prev;
}						t_list_node;

typedef struct s_stacks
{
	t_list_node			*a;
	t_list_node			*b;
	t_list_node			*log;
	// t_list_node			*sort_sizes_a;
	// t_list_node			*sort_sizes_b;
	// t_list_node			*list_sizes_min;
	// t_list_node			*list_sizes_mid;
	// t_list_node			*list_sizes_max;
}						t_stacks;

int			ft_printf(const char *format, ...);

t_list_node	*ft_lstnew(void *content);
void		ft_lstadd_front(t_list_node **lst, t_list_node *new);
int			ft_lstsize(t_list_node *lst, size_t init_size, t_list_node *head);
void		ft_lstpop(t_list_node **lst);
void		ft_lstclear(t_list_node **current, t_list_node *head);

int			push(t_list_node **src, t_list_node **dest, t_stacks *stacks);
int			swap(t_list_node **lst, t_stacks *stacks);
int			rotate(t_list_node **lst, t_stacks *stacks);
int			rrotate(t_list_node **lst, t_stacks *stacks);
void		del(t_list_node *node);
void		print_lst_content(t_list_node *current, t_list_node *head);
void		print_lst_ranks(t_list_node *current, t_list_node *head);
int			is_sorted(t_list_node *lst);
void		print_lists(t_stacks *stacks);
void		print_ranks(t_stacks *stacks);
void		print_log(t_list_node *current, t_list_node *head);

// Utils
int			abs(int x);
long		ft_atoi(char *str);
int			ft_isnumber(char *str);
void		ps_error(void);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

// Halfway sort utils
void		send_bottom_ranks(t_stacks *stacks);
void		send_top_ranks(t_stacks *stacks);
int			get_node_dist(t_list_node *current, int rank);

// Init files
int			init(int argc, char *argv[], t_stacks *stacks);
int			check_and_rank(t_list_node *lst, t_list_node *head);

// Optimiser
void		log_op(t_list_node **log, char *operation);
void		naive_pass(t_stacks *stacks);
void		delete_nodes(t_list_node **lst);
void		replace_nodes(t_list_node **lst, t_list_node *new);
int			rotate_log(t_list_node **lst);

// Main insertion sort entry point
int			sort(t_stacks *stacks, size_t len);
void		halfway_sort(t_stacks *stacks);

#endif