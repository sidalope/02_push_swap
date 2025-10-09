/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:24:26 by abisani           #+#    #+#             */
/*   Updated: 2025/10/09 16:32:01 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list_node
{
	void				*content;
	size_t				rank;
	struct s_list_node	*next;
	struct s_list_node	*prev;
}						t_list_node;

typedef struct s_stacks
{
	struct s_list_node	*a;
	struct s_list_node	*b;
}						t_stacks;

void		ft_clst_insert(t_list_node **lst, t_list_node *new);
int			ft_printf(const char *format, ...);
t_list_node	*ft_lstnew(void *content);
void		ft_lstadd_front(t_list_node **lst, t_list_node *new);
void		ft_lstadd_back(t_list_node **lst, t_list_node *new);
int			ft_lstsize(t_list_node *lst);
t_list_node	*ft_lstlast(t_list_node *lst);
void		ft_lstdelone(t_list_node *lst);
void		ft_lstclear(t_list_node **lst, void (*del)(void*));
void		ft_lstiter(t_list_node *lst, void (*f)(void *));
int			ft_atoi(const char *str);
int			push(t_list_node **src, t_list_node **dest);
int			swap(t_list_node **lst);
int			rotate(t_list_node **lst);
int			rrotate(t_list_node **lst);
void		del(t_list_node *node);
void		print_content(void *content);

#endif