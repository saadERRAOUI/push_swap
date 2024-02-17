/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:35:42 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/17 15:38:51 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
