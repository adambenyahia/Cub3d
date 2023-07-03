/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:13:22 by beadam            #+#    #+#             */
/*   Updated: 2021/11/13 01:13:23 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur;
	t_list	*last;

	cur = lst;
	last = lst;
	while (cur)
	{
		last = cur;
		cur = cur->next;
	}
	return (last);
}
