/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:12:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/12 23:46:29 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int					content;
	int					index;
	struct s_stack		*prev;
	struct s_stack		*next;
}					t_stack;

typedef struct s_pile
{
	t_stack				*a;
	t_stack				*b;
}					t_pile;

int			ft_atoi_check(const char *str, int *number);
int			ft_strcmp(const char *s1, const char *s2);
int			get_max_index(t_stack *a);
void		index_fill(t_stack **tmp, int index);
void		ft_lstadd_back(t_stack **s, t_stack *new);
void		ft_lstadd_front(t_stack **s, t_stack *new);
void		swap_stack(t_stack *s);
void		rot_stack(t_stack *s);
void		rev_rot_stack(t_stack *s);
void		rm_stack(t_stack **s, int *content);
void		rot_stack_orch(t_stack *a, t_stack *b, char c);
void		rev_rot_stack_orch(t_stack *a, t_stack *b, char c);
void		swap_stack_orch(t_stack *a, t_stack *b, char c);
void		push_stack(t_stack **s, t_stack **d, char c);
void		ft_sort(t_stack *a, t_stack *b, int len);
void		ft_sort_medium(t_stack *a, t_stack *b, int len, int flag);
void		ft_sort_small(t_stack *a, t_stack *b, int len);
void		bubble_sort(int *arr, int n);
t_stack		*ft_lstlast(t_stack *s);
void		print_stack(t_stack *s, char c);

#endif