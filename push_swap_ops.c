/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:45:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/01/28 15:52:13 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pb pa
void	push_stack(t_stack **s, t_stack **d, char c)
{
	int		nbr;
	t_stack	*tmp;
	
	printf("p%c\n", c);//! change to ft_printf();
	rm_stack(s, &nbr);
	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->content = nbr;
	ft_lstadd_front(d, tmp);
}

//sa sb ss
void	swap_stack(t_stack *s)
{
	int	tmp;

	tmp = s->content;
	s->content = s->next->content;
	s->next->content = tmp;
}

//ra rb rr
void	rot_stack(t_stack *s)
{
	t_stack	*tmp;
	int		t;
	
	tmp = s;
	while(s->next && s->next != tmp)
	{
		t = s->next->content;
		s->next->content = s->content;
		s->content = t;
		s = s->next;
	}
}

//rra rrb rrr
void	rev_rot_stack(t_stack *s)
{
	t_stack	*tmp;
	int		t;
	
	tmp = s;
	while(s->prev && s->prev != tmp)
	{
		t = s->prev->content;
		s->prev->content = s->content;
		s->content = t;
		s = s->prev;
	}
}

//remove node from the stack
void	rm_stack(t_stack **s, int *content)
{
	t_stack *_prev;
	t_stack *_curr;

	if (!s || !(*s))
		return ;
	*content = (*s)->content;
	_curr = *s;
	_prev = (*s)->prev;
	*s = (*s)->next;
	_prev->next = *s;
	(*s)->prev = _prev;
	free(_curr);
}
