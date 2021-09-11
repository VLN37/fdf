/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:45:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/02 13:10:55 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief appends at most SIZE bytes of SRC into the end of DEST, overwriting
 * its terminating NULL byte and adding a new one. User should guarantee that
 * DEST has enough space to receive SIZE bytes of SRC.
 * @param dest the string to be appended
 * @param src the string append
 * @param size the maximum amount of bytes that dest should have
 * @return size_t - the initial length of dest plus the length of src
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src) + i);
	while (dest[i] && i < size)
		i++;
	j = i;
	while (src[j - i] && j < size - 1)
	{
		dest[j] = src[j - i];
		j++;
	}
	if (j < size)
		dest[j] = '\0';
	return (ft_strlen(src) + i);
}
