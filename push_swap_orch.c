/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_orch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:47:35 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/18 22:31:34 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_stack_orch(t_stack *a, t_stack *b, char c)
{
	ft_printf("r%c\n", c);
	if (c == 'r')
	{
		rot_stack(a);
		rot_stack(b);
	}
	else if (c == 'a')
		rot_stack(a);
	else
		rot_stack(b);
}

void	rev_rot_stack_orch(t_stack *a, t_stack *b, char c)
{
	ft_printf("rr%c\n", c);
	if (c == 'r')
	{
		rev_rot_stack(a);
		rev_rot_stack(b);
	}
	else if (c == 'a')
		rev_rot_stack(a);
	else
		rev_rot_stack(b);
}

void	swap_stack_orch(t_stack *a, t_stack *b, char c)
{
	ft_printf("s%c\n", c);
	if (c == 's')
	{
		swap_stack(a);
		swap_stack(b);
	}
	else if (c == 'a')
		swap_stack(a);
	else
		swap_stack(b);
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < n - 1)
	{
		j = -1;
		while (++j < (n - i - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void	index_fill(t_stack **tmp, int index)
{
	while ((*tmp) && (*tmp)->index != 0)
	{
		(*tmp)->index = ++index;
		(*tmp) = (*tmp)->next;
	}
}
/* //! ********************************************** /
	!TO REMOVE 
*/ //! ********************************************** /
// void	print_stack(t_stack *s, char c)
// {
// 	t_stack *tmp;

// 	printf("\n___STACK %c\n\n", c);
// 	if (!s) return ;
// 	printf("content: %i, index: %i, addr: 
//%p, prev: %p, next: %p\n", s->content, s->index, s, s->prev, s->next);
// 	tmp = s->next;
// 	while (tmp && tmp != s)
// 	{
// 		printf("content: %i, index: %i, addr: %p,prev: 
//%p, next: %p\n", tmp->content, tmp->index, tmp, tmp->prev, tmp->next);
// 		tmp = tmp->next;
// 	}
// }
