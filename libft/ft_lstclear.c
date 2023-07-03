/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:14:20 by beadam            #+#    #+#             */
/*   Updated: 2021/11/13 01:14:22 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tcur;

	while (*lst)
	{
		tcur = *lst;
		*lst = (*lst)->next;
		del(tcur->content);
		free(tcur);
	}
	*lst = NULL;
}
