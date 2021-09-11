/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:15:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/02 12:50:28 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcount(char const *s, char c, int *l)
{
	int	i;

	*l = 0;
	i = 0;
	if (c == 0)
		return (1);
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	return (i);
}

static int	strsize(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

/**
 * @brief Receives a string and returns a freshly allocated array of strings.
 * The string is cut every time C is found, removing it from the string.
 *
 * @param s the string to be separated
 * @param c the delimiter character
 * @return char** - freshly allocated array of strings that needs to be
 * freed later
 */
char	**ft_split(char const *s, char c)
{
	int		strctr;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	strctr = strcount(s, c, &i) + 1;
	res = (char **)malloc(sizeof(char *) * strctr);
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			res[i] = ft_calloc(strsize((char *)s, c) + 1, sizeof(char));
		if (*s)
			ft_strlcpy(res[i++], s, strsize((char *)s, c) + 1);
		while (*s && *s != c)
			s++;
		while (*s == c && *s)
			s++;
	}
	res[i] = NULL;
	return (res);
}
