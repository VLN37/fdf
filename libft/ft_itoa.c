/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:33:12 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/08 01:29:23 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	setvariables(int nbr, int *sign, int *size_str)
{
	int	i;

	*size_str = 0;
	i = 0;
	if (nbr < 0)
	{
		i++;
		*sign *= -1;
		nbr *= -1;
	}
	if (nbr == 0)
		*size_str += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	*size_str = *size_str + i + 1;
}

static void	putnbr(int nbr, char *res, int *sign)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		res[i++] = '8';
		nbr = nbr / 10;
	}
	if (nbr == 0)
		res[i++] = '0';
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		res[i] = (nbr % 10) + 48;
		i++;
		nbr = nbr / 10;
	}
	if (*sign == -1)
		res[i] = '-';
}

static void	reverse_string(char *tab)
{
	int	i;
	int	buffer;
	int	size_str;

	size_str = ft_strlen(tab);
	i = 0;
	while (i < size_str / 2)
	{
		buffer = tab[i];
		tab[i] = tab[size_str - i - 1];
		tab[size_str - i - 1] = buffer;
		i++;
	}
}

/**
 * @brief Receives an int number and returns it as a freshly allocated string
 * @param nbr the number to be converted
 * @return char * - the address of the allocated string
 */
char	*ft_itoa(int nbr)
{
	int		size_str;
	int		sign;
	char	*res;

	sign = 1;
	setvariables(nbr, &sign, &size_str);
	res = (char *)ft_calloc(size_str, sizeof(char));
	if (!res)
		return (NULL);
	putnbr(nbr, res, &sign);
	reverse_string(res);
	return (res);
}
