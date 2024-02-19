/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_orch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:47:35 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 15:04:03 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void rot_stack_orch(t_stack *, t_stack *, int);
	@__DESC   : utility function to orchestrate the rotation opertations
		weither to rotate the t_stack *a or t_stack *b or both, and prints
		the following operation sign.
	@__DATE   : 05-01-2024
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void rev_rot_stack_orch(t_stack *, t_stack *, int);
	@__DESC   : utility function to orchestrate the reverse rotation 
		opertations weither to reverse rotate the t_stack *a or 
		t_stack *b or both, and prints the following operation sign.
	@__DATE   : 05-01-2024
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void swap_stack_orch(t_stack *, t_stack *, int);
	@__DESC   : utility function to orchestrate the swap opertations
		weither to swap the t_stack *a or t_stack *b or both, and prints
		the following operation sign.
	@__DATE   : 05-01-2024
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void bubble_sort(int *arr, int n);
	@__DESC   : utility function to bubble sort the int *arr passed in
		params with its length n.
	@__DATE   : 05-01-2024
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void index_fill(t_stack **, int);
	@__DESC   : utility function to put the appropriate index on each node
		index property of the t_stack *tmp starting from an index passed
		in the params.
	@__DATE   : 05-01-2024
********************************************************************** */
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
