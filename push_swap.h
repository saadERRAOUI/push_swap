/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:12:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/01/29 01:03:53 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//define the struct of the stack
/*
	head : {0, 0, next} -> {3, 1, next} -> {5, 2, next} -> {3, 3, next} -> {-4, 4, head};
*/
typedef struct		s_stack
{
	int					content;
	int					index;
	struct s_stack		*prev;
	struct s_stack		*next;
	
}					t_stack;

typedef struct		s_pile
{
	t_stack				*a;
	t_stack				*b;
}					t_pile;

int			ft_atoi_check(const char *, int *);
int			ft_strcmp(const char *, const char *);
void		ft_lstadd_back(t_stack **, t_stack *);
void		ft_lstadd_front(t_stack **, t_stack *);
void		swap_stack(t_stack *);
void		rot_stack(t_stack *);
void		rev_rot_stack(t_stack *s);
void		rm_stack(t_stack **, int *);
void		rot_stack_orch(t_stack *a, t_stack *b, char c);
void		rev_rot_stack_orch(t_stack *a, t_stack *b, char c);
void		swap_stack_orch(t_stack *a, t_stack *b, char c);
void		push_stack(t_stack **s, t_stack **d, char c);
t_stack		*ft_lstlast(t_stack *);


/*to delete*/
void	print_stack(t_stack *s, char c);
#endif