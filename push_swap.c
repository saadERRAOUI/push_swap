/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:34:40 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/17 00:00:13 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			{
				ft_sort_small(a, b, a->prev->index + 1);
				free_on_exit(a);
			}
			else
				ft_sort(a, b, a->prev->index + 1);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
