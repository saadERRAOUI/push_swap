/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:15:33 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 14:51:05 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : char *ft_strjoin(char const *, char const *);
	@__DESC   : utility function that joins the 2 passed const char * into
		one char *.
	@__DATE   : 05-12-2023
********************************************************************** */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = 0;
	free ((void *)s1);
	return (s);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : int	count_words(char const *, char);
	@__DESC   : utility function for the ft_split() returns the count (Int)
		of the words existing in the const char *s, using the seperator
		char c.
	@__DATE   : 05-12-2023
********************************************************************** */
int	count_words(char const *s, char c)
{
	int	i;
	int	chuncks_number;

	i = 0;
	chuncks_number = 0;
	if (*s == '\0')
		return (chuncks_number);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			chuncks_number += 1;
		i++;
	}
	if (s[i - 1] != c)
		chuncks_number += 1;
	return (chuncks_number);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static int count_word_len(char const *, char );
	@__DESC   : utility function for the ft_split() returns the len count
		(Int) of each word existing in the const char *s, using the seperator
		char c.
	@__DATE   : 05-12-2023
********************************************************************** */
static int	count_word_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : static void	*free_allocation(char **, int);
	@__DESC   : utility function for the ft_split() that frees the allocated
		memory on the split function.
	@__DATE   : 05-12-2023
********************************************************************** */
static void	*free_allocation(char **s, int count)
{
	while (count >= 0)
	{
		free(s[count]);
		count--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

/* **********************************************************************
	@__AUTHOR : ERRAOUI Saad
	@__PROTO  : char **ft_split(char const *, char)
	@__DESC   : utility function that splits a const char *s into seperated
		words using a char c seperator and returns a char ** value, if any 
		error occurs during the split the return value is NULL.
	@__DATE   : 05-12-2023
********************************************************************** */
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		offset;
	int		j;
	int		i;

	offset = 0;
	i = 0;
	str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	while (i < count_words(s, c))
	{
		str[i] = malloc((count_word_len(&s[offset], c) + 1) * sizeof(char));
		if (!str[i])
			return (free_allocation(str, i));
		j = 0;
		while (s[offset] == c)
			offset++;
		while (s[offset] && s[offset] != c)
			str[i][j++] = s[offset++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (free((void *)s), str);
}
