/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:21:45 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/07 23:31:52 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrimmed(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}


/**
 * @brief determines the starting parameters for trim to work
 *
 * @param size dereferences the amount of bytes that will be written
 * @param start dereferences the starting index to work with
 */
static void	setvariables(size_t *size, size_t *start,
char const *s1, char const *set)
{
	int	i;

	i = 0;
	if (!s1)
		return ;
	*size = ft_strlen((char *)s1);
	while (istrimmed(s1[i], set))
	{
		*size -= 1;
		i++;
	}
	*start = i;
	i = ft_strlen((char *)s1);
	if (*size > 1)
	{
		while (istrimmed(s1[i - 1], set))
		{
			*size -= 1;
			i--;
		}
	}
}

/**
 * @brief trims SET from the start and end of the string s1, returns a freshly
allocated string with the remaining characters
 *
 * @param s1 the string to be trimmed
 * @param set the set of characters that should be removed
 * @return char* the address of the freshly allocated string
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size;
	size_t		start;
	char		*res;

	if (!s1)
		return (NULL);
	setvariables(&size, &start, s1, set);
	res = (char *)ft_calloc(size + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[start], size + 1);
	return (res);
}
