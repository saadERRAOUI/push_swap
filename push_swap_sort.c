/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:13:51 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/15 12:53:34 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_hopp(int len)
{
	if (len >= 4 && len <= 19)
		return (2);
	else if (len <= 99)
		return (14);
	return (35);
}

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

static void	fill_tab(t_stack *a, int **tab, int l)
{
	int	i;

	i = 0;
	(*tab) = (int *)malloc(sizeof(int) * l);
	while (i < l)
	{
		(*tab)[i] = a->content;
		a = a->next;
		i++;
	}
	bubble_sort((*tab), l);
}

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
