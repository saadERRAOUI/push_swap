/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:05:59 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/12 15:52:43 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

int	ft_atoi_check(const char *str, int *number)
{
	int		i;
	int		sign;

	(*number) = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if ((*number) < 0 && sign == -1)
			return (0);
		else if ((*number) < 0 && sign == 1)
			return (-1);
		(*number) = (*number) * 10 + str[i++] - '0';
	}
	(*number) *= sign; 
	return (1);
}

t_stack	*ft_lstlast(t_stack *st)
{
	t_stack *tmp;
	
	if (!st)
		return (NULL);
	tmp = st;
	while(st->next && st->next != tmp)
		st = st->next;
	return (st);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	if (!(*lst))
	{
		new->prev = new;
		new->next = new;
		(*lst) = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	new->prev = tmp;
	new->next = (*lst);
	tmp->next = new;
	(*lst)->prev = new;
	new->index = tmp->index + 1;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	// if (!(*lst))
	// {
	// 	printf("ENTERS HEEERE ###!\n\n");
	// 	(*lst) = new;
	// 	(*lst)->next = new;
	// 	(*lst)->prev = new;
	// }
	if (!(*lst))
	{
		new->prev = new;
		new->next = new;
		new->index = 0;
		(*lst) = new;
		return ;
	}
	ft_lstadd_back(lst, new);
	rev_rot_stack((*lst));
}

int get_max_index(t_stack *a)
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
