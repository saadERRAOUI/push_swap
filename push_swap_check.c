/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:13:18 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 14:36:36 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	ft_is_sorted(t_stack *);
	@__DESC   : check function that returns a 0 if the t_stack *s is not
		sorted and 1 if it is the case. 
	@__DATE   : 10-12-2023
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : t_stack	*fill_stack(int, char **);
	@__DESC   : utility function that fills the t_stack *a (return value)
		with the integer values of the args in the char **av 
	@__DATE   : 10-12-2023
********************************************************************** */
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
		if (!node)
			return (NULL);
		(*node) = (t_stack){nbr, i, NULL, NULL};
		ft_lstadd_back(&a, node);
		free(av[i]);
		av[i] = NULL;
	}
	tmp = ft_lstlast(a);
	a->prev = tmp;
	tmp->next = a;
	return (free(av), av = NULL, a);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	check_occurrence(char **);
	@__DESC   : check function that checks wheither there is a redundancy
		of the args passed in the char **av, if no redundancy returns 1,
		if yes returns 0
	@__DATE   : 10-12-2023
********************************************************************** */
int	check_occurrence(char **av)
{
	int		i;
	int		j;
	int		nbr1;
	int		nbr2;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		ft_atoi_check(av[i], &nbr1);
		j = 0;
		while (av[j])
		{
			ft_atoi_check(av[j], &nbr2);
			if ((nbr2 == nbr1) && (i != j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : char **strip_args(int, char **, int *);
	@__DESC   : utility function that takes the arg count and arg values,
		checks on the validity of each value (is not blank), returns NULL
		if at least one is NULL, and returns seperated values in char **s
		with the info on the number of args.
	@__DATE   : 11-02-2024
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	validate_stack(char **, int);
	@__DESC   : check function that takes the values count and the values
		char **s passed from the strip_args() function, and checks weither
		all the values are integers, if it is the case returns 1, if not
		returns 0,
	@__DATE   : 10-12-2023
********************************************************************** */
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
