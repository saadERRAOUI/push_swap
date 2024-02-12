/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:34:40 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/12 15:54:40 by serraoui         ###   ########.fr       */
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

static int get_max_index(t_stack *a)
{
	int 	max_i;
	int		max_c;
	int 	flag;
	t_stack *tmp;
	
	tmp = a;
	flag = 0;
	max_c = a->content;
	max_i = a->index;
	while ((a->next != tmp && !flag) || (a != tmp && flag))
	{
		if (a->content > max_c)
		{
			max_c = a->content;
			max_i = a->index;
		}
		a = a->next;
		flag = 1;
	}
	return (max_i);
}

static int	ft_is_sorted(t_stack *s)
{
	t_stack *tmp;
	t_stack *needle;
	int		flag = 0;

	tmp = s;
	while (
		(tmp->next && tmp->next != s && !flag) ||
		(tmp && tmp != s && flag)
	)
	{
		needle = s;
		while(needle != tmp)
		{
//printf("__NDL %i -> __TMP %i\n", needle->content, tmp->content);
			if (needle->content > tmp->content)
				return (0);
			needle = needle->next;
		}
		tmp = tmp->next;
		flag = 1;
	}
	return (1);
}
static void ft_sort_medium(t_stack *a, t_stack *b, int len, int flag); //!to__remove

static void	ft_sort_small(t_stack *a, t_stack *b, int len)
{
	int max_index;
	
	if (len > 3)
		ft_sort_medium(a, b, len, 1);
	if (len == 2)
	{
		swap_stack_orch(a, NULL, 'a');
		exit(0);
	}
	else if (len == 3)
	{
		max_index = get_max_index(a);
		if (max_index == 1)
			rev_rot_stack_orch(a, NULL, 'a');
		else if (max_index == 0)
			rot_stack_orch(a, NULL, 'a');
		swap_stack_orch(a, NULL, 'a');
		return ;
	}
}

static void ft_sort_medium(t_stack *a, t_stack *b, int len, int flag)
{
	int max_index;
	
	max_index = get_max_index(a);
	if (len == 4 || (flag == 0 && len == 5))
	{
		if (max_index == 3 || max_index == 2)
			rev_rot_stack_orch(a, NULL, 'a');
		if (max_index == 2)
			rev_rot_stack_orch(a, NULL, 'a');
		if (max_index == 1)
			swap_stack_orch(a, NULL, 'a');
		push_stack(&a, &b, 'a');
	}
	else if (len == 5)
	{
		if (max_index == 4 || max_index == 3 || max_index == 2)
			rev_rot_stack_orch(a, NULL, 'a');
		if (max_index == 3 || max_index == 2)
			rev_rot_stack_orch(a, NULL, 'a');
		if (max_index == 2)
			rev_rot_stack_orch(a, NULL, 'a');
		if (max_index == 1)
			swap_stack_orch(a, NULL, 'a');
		push_stack(&a, &b, 'a');
		ft_sort_medium(a, b, 5, 0);
	}
	ft_sort_small(a, b, 3);
	push_stack(&b, &a, 'b');
	rot_stack_orch(a, b, 'a');
	if (len == 5)
	{
		push_stack(&b, &a, 'b');
		rot_stack_orch(a, b, 'a');
	}
	exit(0);
}


static t_stack *fill_stack(int ac, char **av)
{
	int i;
	int nbr;
	t_stack *a;
	t_stack *tmp;
	t_stack *node;

	i = 0;
	a = NULL;
	while (++i < ac)
	{
		ft_atoi_check(av[i], &nbr);
		node = (t_stack *)malloc(sizeof(t_stack));
		(*node) = (t_stack) {nbr, i - 1, NULL, NULL};
		ft_lstadd_back(&a, node);
	}
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
	t_stack *b = NULL;

	if (ac >= 1)
	{
		// printf("__VALID %i\n", validate_stack(av, ac));
		// printf("__OCC %i\n", check_occurrence(av));
		if (validate_stack(av, ac) && check_occurrence(av))
		{
			a = fill_stack(ac, av);
			// (void)b;
			if (ft_is_sorted(a))
				return(printf("ALL GOOD\n"), 1);
			if (a->prev->index <= 4)
			{
				ft_sort_small(a, b, a->prev->index + 1);
				return (1);
			}
			else
				ft_sort(a, b, a->prev->index + 1);
		}
		else
			printf("Error\n");
	}
	return (0);
}