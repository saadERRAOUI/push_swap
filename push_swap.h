/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:12:28 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/17 15:37:22 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int					content;
	int					index;
	struct s_stack		*prev;
	struct s_stack		*next;
}					t_stack;

int			ft_atoi_check(const char *str, int *number);
int			count_words(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
int			get_max_index(t_stack *a);
int			ft_is_sorted(t_stack *s);
int			validate_stack(char **av, int ac);
int			check_occurrence(char **av);
int			is_all_blank(char *s);
size_t		ft_strlen(const char *s);
void		index_fill(t_stack **tmp, int index);
void		ft_lstadd_back(t_stack **s, t_stack *new);
void		ft_lstadd_front(t_stack **s, t_stack *new);
void		swap_stack(t_stack *s);
void		rot_stack(t_stack *s);
void		rev_rot_stack(t_stack *s);
void		rm_stack(t_stack **s, int *content);
void		rot_stack_orch(t_stack *a, t_stack *b, char c);
void		rev_rot_stack_orch(t_stack *a, t_stack *b, char c);
void		swap_stack_orch(t_stack *a, t_stack *b, char c);
void		push_stack(t_stack **s, t_stack **d, char c);
void		ft_sort(t_stack *a, t_stack *b, int len);
void		ft_sort_medium(t_stack *a, t_stack *b, int len, int flag);
void		ft_sort_small(t_stack *a, t_stack *b, int len);
void		bubble_sort(int *arr, int n);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		**strip_args(int ac, char **av, int *nbr);
void		free_on_exit(t_stack *a);
void		print_stack(t_stack *s, char c);
void		free_s(char **s, int _ac);
t_stack		*ft_lstlast(t_stack *s);
t_stack		*fill_stack(int ac, char **av);

#endif