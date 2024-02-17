/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:07:47 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/17 00:26:33 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int rot_ops(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "ra\n"))
	{
		if ((*a) && (*a)->prev->index >= 1)
			rot_stack(*a);
	}
	else if (!ft_strcmp(s, "rb\n"))
	{
		if ((*b) && (*b)->prev->index >= 1)
			rot_stack(*b);
	}
	else if (!ft_strcmp(s, "rr\n"))
	{
		if (
			((*b) && (*b)->prev->index >= 1)
			&& ((*a) && (*a)->prev->index >= 1)
		)
		{			
			rot_stack(*a);
			rot_stack(*b);
		}
	}
	else
		return (0);
	return (1);
}

int swap_ops(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
	{
		if ((*a) && (*a)->prev->index >= 1)
			swap_stack(*a);
	}
	else if (!ft_strcmp(s, "sb\n")
		&& (*b) && ((*b)->prev->index >= 1)
	)
	{
		if ((*b) && (*b)->prev->index >= 1)
			swap_stack(*b);
	}
	else if (!ft_strcmp(s, "ss\n"))
	{
		if (
			((*b) && (*b)->prev->index >= 1)
			&& ((*a) && (*a)->prev->index >= 1)
		)
		{			
			swap_stack(*a);
			swap_stack(*b);
		}
	}
	else
		return (0);
	return (1);
}

int rev_rot_ops(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "rra\n"))
	{
		if ((*a) && (*a)->prev->index >= 1)
		rev_rot_stack(*a);
	}
	else if (!ft_strcmp(s, "rrb\n"))
	{
		if ((*b) && (*b)->prev->index >= 1)
			rev_rot_stack(*b);
	}
	else if (!ft_strcmp(s, "rr\n"))
	{
		if (
			((*b) && (*b)->prev->index >= 1)
			&& ((*a) && (*a)->prev->index >= 1)
		)
		{			
			rev_rot_stack(*a);
			rev_rot_stack(*b);
		}
	}
	else
		return (0);
	return (1);
}

int push_ops(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "pb\n"))
	{
		if (*a)	
			push_stack(a, b, 'p');
	}
	else if (!ft_strcmp(s, "pa\n"))
	{
		if (*b)
			push_stack(b, a, 'p');
	}
	else
		return (0);
	return (1);
}

int	read_ops(t_stack **a, t_stack **b)
{
	char	*s;

	while((s = get_next_line(0)) != NULL)
	{
		if (
			rot_ops(a, b, s)
			|| push_ops(a, b, s)
			|| rev_rot_ops(a, b, s)
			|| swap_ops(a, b, s)
		)
			free(s);
		else
		{
			free(s);
			return (0);
		}
	}
	return (1);
}

int	ft_e(int ac, char **av)
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
				return (free(a), ft_printf("Error\n"), 0);
			// print_stack(a, 'a');
			if (ft_is_sorted(a) && a && a->prev->index == (_ac - 1))
				return (free(a), ft_printf("OK\n"), 0);
			return (free(a), ft_printf("KO\n"), 0);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}

int main(int ac, char **av)
{
	ft_e(ac, av);
	system("leaks checker");
}