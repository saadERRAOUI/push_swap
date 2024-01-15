/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:12:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/01/16 00:38:45 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

//define the struct of the stack
/*
	head : {0, 0, next} -> {3, 1, next} -> {5, 2, next} -> {3, 3, next} -> {-4, 4, head};
*/
typedef struct		s_stack
{
	int						content;
	int						index;
	struct s_stack			*prev;
	struct s_stack			*next;
	
}					t_stack;

typedef struct		s_pile
{
	t_stack         *a;
	t_stack         *b;
}					t_pile;


int			ft_atoi_check(const char *str, int *number);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *st);

#endif