/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:13:18 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/17 00:15:12 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *s)
{
	t_stack	*tmp;
	t_stack	*needle;
	int		flag;

	tmp = s;
	flag = 0;
	if (!s)
		return (0);
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

t_stack	*fill_stack(int ac, char **av)
{
	int		i;
	int		nbr;
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*node;

	i = -1;
	a = NULL;
	if (!av || !(*av))
		return (NULL);
	while (++i < ac)
	{
		ft_atoi_check(av[i], &nbr);
		node = (t_stack *)malloc(sizeof(t_stack));
		(*node) = (t_stack){nbr, i, NULL, NULL};
		ft_lstadd_back(&a, node);
		free(av[i]);
		av[i] = NULL;
	}
	tmp = ft_lstlast(a);
	a->prev = tmp;
	tmp->next = a;
	free(av);
	av = NULL;
	return (a);
}

int	check_occurrence(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!av)
		return (0);
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

char	**strip_args(int ac, char **av, int *nbr)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	while (++i < ac)
	{
		if (!is_all_blank(av[i]))
			return (NULL);
		s = ft_strjoin(s, " ");
		s = ft_strjoin(s, av[i]);
	}
	(*nbr) = count_words(s, ' ');
	return (ft_split(s, ' '));
}

int	validate_stack(char **av, int ac)
{
	int	i;
	int	nbr;

	i = 0;
	if (!av)
		return (0);
	while (av[i] && ft_atoi_check(av[i], &nbr))
		i++;
	return (i == ac);
}
