/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:40:46 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/04 19:04:23 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//includes the NEW node to the beggining of the list pointed to by begin
void	ft_lstadd_front(t_list **begin, t_list *new)
{
	if (!begin)
		return ;
	new->next = *begin;
	*begin = new;
}
