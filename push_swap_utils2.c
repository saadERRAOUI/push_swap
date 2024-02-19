/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:02:31 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 15:52:19 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static void	ft_hndl_m_s(t_stack *, int, int);
	@__DESC   : utility function helper used in the ft_sort_medium()
		function that execute operations (reverse rotate and swap) based on
		max content index of all the nodes in the t_stack *a.
	@__DATE   : 10-12-2023
********************************************************************** */
static void	ft_hndl_m_s(t_stack *a, int max_index, int flag)
{
	if (max_index == 4
		|| (max_index == 3 && flag)
		|| (max_index == 2 && flag)
	)
		rev_rot_stack_orch(a, NULL, 'a');
	if (max_index == 3 || max_index == 2)
		rev_rot_stack_orch(a, NULL, 'a');
	if (max_index == 2)
		rev_rot_stack_orch(a, NULL, 'a');
	if (max_index == 1)
		swap_stack_orch(a, NULL, 'a');
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void ft_sort_small(t_stack *, t_stack *, int);
	@__DESC   : utility function that sorts the t_stack *a when the length of
		a is less or equal then 5, calls the ft_sort_medium() when len > 3.
	@__DATE   : 10-12-2023
********************************************************************** */
void	ft_sort_small(t_stack *a, t_stack *b, int len)
{
	int	max_index;

	if (len > 3)
		ft_sort_medium(a, b, len, 1);
	if (len == 2)
		swap_stack_orch(a, NULL, 'a');
	else if (len == 3)
	{
		max_index = get_max_index(a);
		if (max_index == 1)
			rev_rot_stack_orch(a, NULL, 'a');
		else if (max_index == 0)
			rot_stack_orch(a, NULL, 'a');
		if (a->content > a->next->content)
			swap_stack_orch(a, NULL, 'a');
	}
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void ft_sort_medium(t_stack *, t_stack *, int, int)
	@__DESC   : utility function that sorts the t_stack *a if the len is
		greater or equal then 4.
	@__DATE   : 10-12-2023
********************************************************************** */
void	ft_sort_medium(t_stack *a, t_stack *b, int len, int flag)
{
	int	max_index;

	max_index = get_max_index(a);
	if (len == 4 || (flag == 0 && len == 5))
	{
		ft_hndl_m_s(a, max_index, 0);
		push_stack(&a, &b, 'b');
	}
	else if (len == 5)
	{
		ft_hndl_m_s(a, max_index, 1);
		push_stack(&a, &b, 'b');
		ft_sort_medium(a, b, 5, 0);
	}
	ft_sort_small(a, b, 3);
	push_stack(&b, &a, 'a');
	rot_stack_orch(a, b, 'a');
	if (len == 5)
	{
		push_stack(&b, &a, 'a');
		rot_stack_orch(a, b, 'a');
	}
	free_on_exit(a);
	exit(0);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	get_max_index(t_stack *);
	@__DESC   : utility function that returns index of the node that has
		max of all the contents on the t_stack *a.
	@__DATE   : 10-12-2023
********************************************************************** */
int	get_max_index(t_stack *a)
{
	int		max_i;
	int		max_c;
	int		flag;
	t_stack	*tmp;

	tmp = a;
	flag = 0;
	max_c = a->content;
	max_i = a->index;
	while ((a->next != tmp && !flag) || (a != tmp && flag))
	{
		if (a->content > max_c)
		{
			max_c = a->content;
			max_i = a->index;
		}
		a = a->next;
		flag = 1;
	}
	return (max_i);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	ft_strcmp(const char *, const char *);
	@__DESC   : utility function to compare between two strings s1 and s2,
		return value > 0 if s1 is greater then s2, value < 0 s1 is less
		then s2 or value == 0 is s1 and s2 are the same.
	@__DATE   : 10-12-2023
********************************************************************** */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
