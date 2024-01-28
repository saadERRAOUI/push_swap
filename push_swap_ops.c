/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:45:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/01/28 04:01:23 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pb pa
// void	push_stack(t_stack *s, t_stack *d, char c)
// {
// 	(void)c;
// 	//ft_lstadd_front(&d, s);
// }

//sa sb ss
void	swap_stack(t_stack *s, char c)
{
	int	tmp;

	(void)c; //!
	tmp = s->content;
	s->content = s->next->content;
	s->next->content = tmp;
}

//ra rb rr
void	rot_stack(t_stack *s, char c)
{
	t_stack	*tmp;
	int		t;
	
	tmp = s;
	(void)c;//!
	while(s->next && s->next != tmp)
	{
		t = s->next->content;
		s->next->content = s->content;
		s->content = t;
		s = s->next;
	}
}

//rra rrb rrr
void	rev_rot_stack(t_stack *s, char c)
{
	t_stack	*tmp;
	int		t;
	
	tmp = s;
	(void)c;//!
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
	//int		i;

	if (!s || !(*s))
		return ;
	// tmp = (*s);
	// (*content) = tmp->content;
	// (*s) = (*s)->next;
	// printf("\nAddress__ == %p\n", *s);
	// free(tmp);
	// // tmp->next = NULL;
	// // tmp->prev = NULL;
	// // tmp = NULL;
	// (*s)->prev = ft_lstlast(*s);
	// tmp = *s;
	// i = 0;
	// while (((*s)) && (*s)->next != tmp)
	// {
	// 	(*s)->index = i;
	// 	(*s) = (*s)->next;
	// 	i++;
	// }
	*content = (*s)->content;
	_curr = *s;
	_prev = (*s)->prev;
	*s = (*s)->next;

	
	_prev->next = *s;
	(*s)->prev = _prev;
	free(_curr);
	//return (*s);
}

// t_stack *rm_stack(t_stack **s, int *content)
// {
//     if (!s || !(*s))
//         return NULL;

//     t_stack *tmp = (*s);
//     (*content) = tmp->content;

//     if ((*s)->next != NULL) {
//         (*s) = (*s)->next;
//         free(tmp);
//         (*s)->prev = NULL;

//         // Update indices
//         t_stack *current = (*s);
//         int i = 0;
//         while (current->next != (*s)) {
//             current->index = i;
//             current = current->next;
//             i++;
//         }
//     } else {
//         // Only one node in the list
//         free(tmp);
//         (*s) = NULL;
//     }
// 	return (*s);
// }