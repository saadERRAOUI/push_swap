/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:35:42 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 15:59:23 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	is_all_blank(char *);
	@__DESC   : utility funciton that checks weither the char *s is all
		blank, every character of the s string equals to ' ', returns 0
		if its the case and 1 if it's not.
	@__DATE   : 10-12-2023
********************************************************************** */
int	is_all_blank(char *s)
{
	int	i;
	int	len;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	len = (int)ft_strlen(s);
	return ((len != i) && len);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : isize_t	ft_strlen(const char *);
	@__DESC   : utility function to calculate the len of the const char *
		passed in the params.
	@__DATE   : 10-12-2023
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void free_on_exit(t_stack *);
	@__DESC   : utility function to free the t_stack *a on exit of the 
		code.
	@__DATE   : 10-12-2023
********************************************************************** */
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

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : void free_s(char **, int);
	@__DESC   : utility function to free the char **s the return value 
		of the strip_args() funciton.
	@__DATE   : 10-12-2023
********************************************************************** */
void	free_s(char **s, int _ac)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (++i < _ac)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}
