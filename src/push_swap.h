/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:24:26 by abisani           #+#    #+#             */
/*   Updated: 2025/10/08 16:27:21 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	size_t			rank;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void	ft_clst_insert(t_list **lst, t_list *new);
int		ft_printf(const char *format, ...);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_atoi(const char *str);
int		push(t_list **src, t_list **dest);
int		rotate(t_list *lst);
int		rrotate(t_list *lst);
int		swap(t_list **src);
void	del(t_list *node);

#endif