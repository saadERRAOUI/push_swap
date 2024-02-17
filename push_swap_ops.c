/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:45:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/16 23:05:24 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **s, t_stack **d, char c)
{
	int		nbr;
	t_stack	*tmp;

	if (c == 'a' || c == 'b')
		ft_printf("p%c\n", c);
	rm_stack(s, &nbr);
	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->content = nbr;
	ft_lstadd_front(d, tmp);
}

void	swap_stack(t_stack *s)
{
	int	tmp;

	tmp = s->content;
	s->content = s->next->content;
	s->next->content = tmp;
}

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
