/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:21:28 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/02 13:18:43 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns the starting address of the first match of TO_FIND in STR, NULL if
//none
char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i < n)
	{
		while (str[i] == to_find[j] && i < n)
		{
			j++;
			i++;
			if (!to_find[j])
				return ((char *)&str[i - j]);
			if (str[i] != to_find[j])
			{
				i = i - j + 1;
				j = 0;
			}
		}
		i++;
	}
	return (NULL);
}
