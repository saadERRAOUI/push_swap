/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:45:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 14:57:29 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void push_stack(t_stack **, t_stack **, char);
	@__DESC   : utility function to push the first element of the t_stack *s
		source to the t_stack *d destination and prints the operation using 
		the passed char c (either "a" or "b").
	@__DATE   : 05-01-2024
********************************************************************** */
void	push_stack(t_stack **s, t_stack **d, char c)
{
	int		nbr;
	t_stack	*tmp;

	if (c == 'a' || c == 'b')
		ft_printf("p%c\n", c);
	rm_stack(s, &nbr);
	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->content = nbr;
	ft_lstadd_front(d, tmp);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void swap_stack(t_stack *);
	@__DESC   : utility function to swap the two first elements of the
		t_stack *s.
	@__DATE   : 05-01-2024
********************************************************************** */
void	swap_stack(t_stack *s)
{
	int	tmp;

	tmp = s->content;
	s->content = s->next->content;
	s->next->content = tmp;
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void rot_stack(t_stack *);
	@__DESC   : utility function to rotate the first element of the
		t_stack *s to be the last one on the stack.
	@__DATE   : 05-01-2024
********************************************************************** */
void	rot_stack(t_stack *s)
{
	t_stack	*tmp;
	int		t;

	tmp = s;
	while (s->next && s->next != tmp)
	{
		t = s->next->content;
		s->next->content = s->content;
		s->content = t;
		s = s->next;
	}
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void rev_rot_stack(t_stack *);
	@__DESC   : utility function to reverse rotate the last element of the
		t_stack *s to be the first one on the stack.
	@__DATE   : 05-01-2024
********************************************************************** */
void	rev_rot_stack(t_stack *s)
{
	t_stack	*tmp;
	int		t;

	tmp = s;
	while (s->prev && s->prev != tmp)
	{
		t = s->prev->content;
		s->prev->content = s->content;
		s->content = t;
		s = s->prev;
	}
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void rm_stack(t_stack *, int);
	@__DESC   : utility function to remove (free) the first node of the 
		t_stack *s and put its content property value in the int *content.
	@__DATE   : 05-01-2024
********************************************************************** */
void	rm_stack(t_stack **s, int *content)
{
	t_stack	*_prev;
	t_stack	*_curr;
	t_stack	*tmp;
	int		index;

	if (!s || !(*s))
		return ;
	index = 0;
	*content = (*s)->content;
	_curr = *s;
	if ((*s)->prev->index != 0)
	{
		_prev = (*s)->prev;
		*s = (*s)->next;
		_prev->next = *s;
		(*s)->prev = _prev;
		(*s)->index = index;
		tmp = (*s)->next;
		index_fill(&tmp, index);
		free(_curr);
		return ;
	}
	free(_curr);
	(*s) = NULL;
}
