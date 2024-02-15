/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:02:31 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/15 14:28:19 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_hndl_m_s(t_stack *a, int max_index)
{
	if (max_index == 4 || max_index == 3 || max_index == 2)
		rev_rot_stack_orch(a, NULL, 'a');
	if (max_index == 3 || max_index == 2)
		rev_rot_stack_orch(a, NULL, 'a');
	if (max_index == 2)
		rev_rot_stack_orch(a, NULL, 'a');
	if (max_index == 1)
		swap_stack_orch(a, NULL, 'a');
}

void	ft_sort_small(t_stack *a, t_stack *b, int len)
{
	int	max_index;

	if (len > 3)
		ft_sort_medium(a, b, len, 1);
	if (len == 2)
	{
		swap_stack_orch(a, NULL, 'a');
		free_on_exit(a);
	}
	else if (len == 3)
	{
		max_index = get_max_index(a);
		printf("ENTERS HERE %i\n", max_index);
		if (max_index == 1)
			rev_rot_stack_orch(a, NULL, 'a');
		else if (max_index == 0)
			rot_stack_orch(a, NULL, 'a');
		if (a->content > a->next->content)
			swap_stack_orch(a, NULL, 'a');
		return ;
	}
}

void	ft_sort_medium(t_stack *a, t_stack *b, int len, int flag)
{
	int	max_index;

	max_index = get_max_index(a);
	if (len == 4 || (flag == 0 && len == 5))
	{
		ft_hndl_m_s(a, max_index);
		push_stack(&a, &b, 'b');
	}
	else if (len == 5)
	{
		ft_hndl_m_s(a, max_index);
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
