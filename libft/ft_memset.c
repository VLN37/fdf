/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:13:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/02 23:22:16 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Overwrites the first LEN bytes of PTR with the character C
void	*ft_memset(void *str, int c, size_t len)
{
	int	size;

	size = len;
	while (len-- > 0)
		*(unsigned char *)str++ = (unsigned char)c;
	return (str - size);
}
