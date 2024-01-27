/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:34:40 by serraoui          #+#    #+#             */
/*   Updated: 2024/01/17 15:49:36 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//! Todo : Update the "printf" function to mine ft_printf
//Todo : Understand the concept of the project
//Todo : Loop on the av stack members and check if they validate the rules
//** RULES #1 - every element is an int number #2 - number of occurrence of each element equals to 1
//!!!!NOTE ---- Comment your code quite well ---


/*
	Todo : Add function to add nodes to my stack
	Todo : check first if the "ac" has 2 or 3 elements --> sort them without using the algo
	Todo : if not -> use the sorting algorithm
	!Note : the first arg should be at the top of the stack
	!Note : check if hanlde case -0 +0 0
*/


// void	ft_sort_small(t_stack *a, int len)
// {

// }

static t_stack *fill_stack(int ac, char **av)
{
	int i;
	int nbr;
	t_stack *a;
	t_stack *tmp;
	t_stack *node;

	i = 0;
	while (++i < ac)
	{
		ft_atoi_check(av[i], &nbr);
		node = (t_stack *)malloc(sizeof(t_stack));
		(*node) = (t_stack) {nbr, i - 1, NULL, NULL};
		ft_lstadd_back(&a, node);
	}
	//Todo : Create circular one !!Important
	tmp = ft_lstlast(a);
	a->prev = tmp;
	tmp->next = a;
	return (a);
}

static int	check_occurrence(char **av)
{
	int i;
	int j;

	i = 0;
	while(av[i])
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


static int	validate_stack(char **av, int ac)
{
	int i;
	int nbr;

	i = 1;
	while (av[i] && ft_atoi_check(av[i], &nbr))
		i++;
	return (i == ac);
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *tmp;
	int nbr, i = 0;
	if (ac >= 1)
	{
		if (validate_stack(av, ac) && check_occurrence(av))
		{
			a = fill_stack(ac, av);
			tmp = a;
			//printf("length : %i\n", a->prev->index + 1);
			// if (s->prev->index <= 2)
			// 	ft_sort_small(a, s->prev->index);
			printf("BEFORE\n\n");
			while(++i < ac)
			{
				printf("content: %i, index: %i, addr: %p, prev: %p, next: %p\n", tmp->content, tmp->index, tmp, tmp->prev, tmp->next);
				tmp = tmp->next;
			}
			// t_stack *node = malloc(sizeof(t_stack));
			// node->content = 23;
			// ft_lstadd_front(&a, node);
			a = rm_stack(&a, &nbr);
			//printf("Removed -> content: %i, index: %i, addr: %p, prev: %p, next: %p\n", tmp->content, tmp->index, tmp, tmp->prev, tmp->next);
			i = 0;
			printf("AFTER\n\n");
			while(++i < ac)
			{
				printf("content: %i, index: %i, addr: %p, prev: %p, next: %p\n", a->content, a->index, a, a->prev, a->next);
				a = a->next;
			}
			printf("\n\nNUMBER : %d\n", nbr);
		}
		else
			printf("Error\n");
	}
	return (0);
}