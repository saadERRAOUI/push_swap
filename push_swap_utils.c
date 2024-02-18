/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:05:59 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/18 22:02:52 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

int	ft_atoi_check(const char *str, int *number)
{
	int	        i;
	int	        sign;
    size_t      n;            

	i = 0;
	sign = 1;
	(*number) = 0;
    n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
        if (n > INT_MAX)
            return (0);
		n = n * 10 + str[i++] - '0';
        printf("___N %zu\n", n);
	}
	return ((*number) = n * sign, 1);
}

t_stack	*ft_lstlast(t_stack *st)
{
	t_stack	*tmp;

	if (!st)
		return (NULL);
	tmp = st;
	while (st->next && st->next != tmp)
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
