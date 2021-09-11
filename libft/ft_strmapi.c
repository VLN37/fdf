/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:21:11 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/05 03:06:48 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a freshly allocated copy of S, applying the function F to all
 * characters
 * @param s the string to copy and apply the function
 * @param f the function that should be applied to the characters in the string
 * @return char* - the starting address of the string that was created
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = -1;
	if (!s || !f)
		return (NULL);
	res = ft_strdup((char *)s);
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = f(i, s[i]);
	return (res);
}
