/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:05:59 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 15:43:01 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static int	ft_isdigit(int);
	@__DESC   : utility function that returns 1 if the arg (ascii) passed 
		is a digit and 0 if not.
	@__DATE   : 10-12-2023
********************************************************************** */
static int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	ft_atoi_check(const char *, int *);
	@__DESC   : utility function that checks weither the const char *str
		is an intger or not, returns 1 if it is the case and 0 if not, and
		the number takes the int value in its content. 
	@__DATE   : 10-12-2023
********************************************************************** */
int	ft_atoi_check(const char *str, int *number)
{
	int		i;
	int		sign;
	size_t	n;

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
		n = n * 10 + str[i++] - '0';
	}
	if ((n > INT_MAX && sign == 1) || (n > 2147483648 && sign == -1))
		return (0);
	return ((*number) = n * sign, 1);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : t_stack	*ft_lstlast(t_stack *st);
	@__DESC   : utility function that returns the last node of the 
		t_stack *st.
	@__DATE   : 10-12-2023
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void ft_lstadd_back(t_stack **, t_stack *);
	@__DESC   : utility function that adds the node t_stack *new to the end
		of the t_stack **lst. 
	@__DATE   : 10-12-2023
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void ft_lstadd_front(t_stack **, t_stack *);
	@__DESC   : utility function that adds the node t_stack *new to the start
		of the t_stack **lst.  
	@__DATE   : 10-12-2023
********************************************************************** */
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
