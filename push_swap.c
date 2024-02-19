/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:34:40 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 14:23:17 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static void sort_small_hndl(t_stack *, t_stack *, int);
	@__DESC   : helper function calls the ft_sort_small() func and frees
			the a stack
	@__DATE   : 17-02-2024
********************************************************************** */
static void	sort_small_hndl(t_stack *a, t_stack *b, int len)
{
	ft_sort_small(a, b, len);
	free_on_exit(a);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	main(int ac, char **av);
	@__DESC   : main function of the push_swap mandartory part
	@__DATE   : 05-12-2023
********************************************************************** */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**s;
	int		_ac;

	b = NULL;
	if (ac > 1)
	{
		s = strip_args(ac, av, &_ac);
		if (validate_stack(s, _ac) && check_occurrence(s))
		{
			a = fill_stack(_ac, s);
			if (!a)
				return (ft_printf("Error\n"), 0);
			else if (ft_is_sorted(a))
				free_on_exit(a);
			else if (a->prev->index <= 4)
				sort_small_hndl(a, b, a->prev->index + 1);
			else
				ft_sort(a, b, a->prev->index + 1);
		}
		else
			return (free_s(s, _ac), ft_printf("Error\n"), 0);
	}
	return (0);
}
