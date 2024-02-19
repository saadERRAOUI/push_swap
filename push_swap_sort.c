/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:13:51 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 15:36:07 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static int choose_hopp(int);
	@__DESC   : utility function to choose the hopp reference based on
		the lenght of the integers table.
	@__DATE   : 05-01-2024
********************************************************************** */
static int	choose_hopp(int len)
{
	if (len >= 4 && len <= 19)
		return (2);
	else if (len <= 99)
		return (14);
	return (35);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static void	push_sort_a(t_stack **, t_stack **, int *);
	@__DESC   : utility function used in the ft_sort() function to push
		elements of stack a to stack b based on the reference in the table
		sorted. 
	@__DATE   : 05-01-2024
********************************************************************** */
static void	push_sort_a(t_stack **a, t_stack **b, int *tab)
{
	int	end;
	int	start;
	int	_len;

	_len = (*a)->prev->index;
	start = 0;
	end = start + choose_hopp(_len);
	while ((*a))
	{
		if ((*a)->content > tab[end])
			rot_stack_orch((*a), NULL, 'a');
		else
		{
			if ((*a)->content < tab[start])
			{
				push_stack(a, b, 'b');
				rot_stack_orch(NULL, (*b), 'b');
			}
			else
				push_stack(a, b, 'b');
			start++;
			if (end < _len)
				end++;
		}
	}
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static void	push_sort_b(t_stack **, t_stack **);
	@__DESC   : utility function used in the ft_sort() function to push the
		elements on the stack b to a based on getting the max index each time
		end push it using rotation and push opertations.
 	@__DATE   : 05-01-2024
********************************************************************** */
static void	push_sort_b(t_stack **a, t_stack **b)
{
	int	_max;

	while ((*b))
	{
		_max = get_max_index((*b));
		if (_max < ((*b)->prev->index + 1) / 2)
		{
			while (_max--)
				rot_stack_orch(NULL, (*b), 'b');
			push_stack(b, a, 'a');
		}
		else if (_max >= ((*b)->prev->index + 1) / 2)
		{
			_max -= ((*b)->prev->index + 1);
			while (_max++)
				rev_rot_stack_orch(NULL, (*b), 'b');
			push_stack(b, a, 'a');
		}
	}
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static void	fill_tab(t_stack *, int **, int);
	@__DESC   : utility function used in the ft_sort() function to fill
		int **tab by the elements of the t_stack *a passed to it the params.
	@__DATE   : 05-01-2024
********************************************************************** */
static void	fill_tab(t_stack *a, int **tab, int l)
{
	int	i;

	i = 0;
	(*tab) = (int *)malloc(sizeof(int) * l);
	if (!(*tab))
		return ;
	while (i < l)
	{
		(*tab)[i] = a->content;
		a = a->next;
		i++;
	}
	bubble_sort((*tab), l);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void index_fill(t_stack **, int);
	@__DESC   : utility function to implement the sorting algorithm on the
		elements of the t_stack *a, in case of the number of elements is 
		greater then 5, and frees the tab and the t_stack *a on exit.
	@__DATE   : 05-01-2024
********************************************************************** */
void	ft_sort(t_stack *a, t_stack *b, int len)
{
	int	*tab;

	fill_tab(a, &tab, len);
	push_sort_a(&a, &b, tab);
	push_sort_b(&a, &b);
	free(tab);
	tab = NULL;
	free_on_exit(a);
}
