/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:07:47 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/17 15:33:39 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
			if (!read_ops(&a, &b))
				return (free_on_exit(a), ft_printf("Error\n"), 0);
			if (ft_is_sorted(a) && a && a->prev->index == (_ac - 1))
				return (free_on_exit(a), ft_printf("OK\n"), 0);
			return (free_on_exit(a), ft_printf("KO\n"), 0);
		}
		else
			return (free_s(s, _ac), ft_printf("Error\n"), 0);
	}
	return (0);
}
