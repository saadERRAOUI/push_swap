/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:34:40 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/14 15:27:55 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_on_exit(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*_tmp;
	int		flag;

	_tmp = a;
	flag = 0;
	while (
		(_tmp == a && flag == 0)
		|| (_tmp != a && flag == 1)
	)
	{
		flag = 1;
		tmp = a;
		a = a->next;
		free(tmp);
		tmp = NULL;
	}
	a = NULL;
}

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
			if (ft_is_sorted(a))
				free_on_exit(a);
			if (a->prev->index <= 4)
				ft_sort_small(a, b, a->prev->index + 1);
			else
				ft_sort(a, b, a->prev->index + 1);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
