/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:34:40 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/13 01:18:52 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_sorted(t_stack *s)
{
	t_stack	*tmp;
	t_stack	*needle;
	int		flag;

	tmp = s;
	flag = 0;
	while (
		(tmp->next && tmp->next != s && !flag)
		|| (tmp && tmp != s && flag)
	)
	{
		needle = s;
		while (needle != tmp)
		{
			if (needle->content > tmp->content)
				return (0);
			needle = needle->next;
		}
		tmp = tmp->next;
		flag = 1;
	}
	return (1);
}

static t_stack	*fill_stack(int ac, char **av)
{
	int		i;
	int		nbr;
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*node;

	i = -1;
	a = NULL;
	while (++i < ac)
	{
		ft_atoi_check(av[i], &nbr);
		node = (t_stack *)malloc(sizeof(t_stack));
		(*node) = (t_stack){nbr, i, NULL, NULL};
		ft_lstadd_back(&a, node);
	}
	tmp = ft_lstlast(a);
	a->prev = tmp;
	tmp->next = a;
	return (a);
}

static int	check_occurrence(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (!ft_strcmp(av[i], "-0") || !ft_strcmp(av[i], "+0"))
			av[i] = "0";
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	**strip_args(int ac, char **av, int *nbr)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	while (++i < ac)
	{
		s = ft_strjoin(s, " ");
		s = ft_strjoin(s, av[i]);
	}
	(*nbr) = count_words(s, ' ');
	return (ft_split(s, ' '));
}

static int	validate_stack(char **av, int ac)
{
	int	i;
	int	nbr;

	i = 0;
	while (av[i] && ft_atoi_check(av[i], &nbr))
		i++;
	return (i == ac);
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
			if (ft_is_sorted(a))
				exit(0);
			if (a->prev->index <= 4)
			{
				ft_sort_small(a, b, a->prev->index + 1);
				return (1);
			}
			else
				ft_sort(a, b, a->prev->index + 1);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
