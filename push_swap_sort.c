/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:13:51 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/12 15:28:28 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bubble_sort(int *arr, int n) {
    int i, j, temp;

	i = -1;
    while (++i < n - 1)
	{
		j = -1;
        while (++j < n - i - 1)
		{
            if (arr[j] > arr[j+1])
			{
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

static void fill_tab(t_stack *a, int **tab, int l)
{
	int i;

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
	int *tab;
	// int i = -1;
	int end, start;
	int hopp;
	int _len;
	int _max;

	fill_tab(a, &tab, len);
	// while (++i < len)
	// 	printf("_TAB[%i] = %i\n", i, tab[i]); 
	_len = a->prev->index;
	if (_len >= 4 && _len <= 19)
		hopp = 2;
	else if (_len <= 99)
		hopp = 14;
	else
		hopp = 35;
	start = 0;
	end = start + hopp;
	while (a)
	{
		// printf("\n___CONTENT %i\n", a->content);
		// print_stack(a, 'a');
		// print_stack(b, 'b');
		// printf("content: %i, index: %i, addr: %p, prev: %p, next: %p\n", a->content, a->index, a, a->prev, a->next);
		if (a->content > tab[end])
			rot_stack_orch(a, NULL, 'a');
		else if (a->content < tab[start])
		{
			push_stack(&a, &b, 'a');
			rot_stack_orch(NULL, b, 'b');
			start++;
			// end++;
			// // //end += hopp;
			if (end < _len)
				end++;
		}
		else
		{
			// if (!b)
			// 	b = (t_stack *)malloc(sizeof(t_stack));
			push_stack(&a, &b, 'a');
			start++;
			if (end < _len)
				end++;
		}
	}
	// print_stack(a, 'a');
	// print_stack(b, 'b');

	//!
	while (b)
	{
		_max = get_max_index(b);
		if (_max < (b->prev->index + 1) / 2)
		{
			while (_max--)
				rot_stack_orch(NULL, b, 'b');
			push_stack(&b, &a, 'b');
		}
		else if (_max >=  (b->prev->index + 1) / 2)
		{
			int temp = (b->prev->index + 1) - _max;
			while (temp--)
				rev_rot_stack_orch(NULL, b, 'b');
			push_stack(&b, &a, 'b');
		}
	}
	free(tab);
	//free(a);
	//system("leaks push_swap");
	//print_stack(a, 'a');
	// print_stack(b, 'b');
}