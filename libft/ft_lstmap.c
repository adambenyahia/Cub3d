/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:14:59 by beadam            #+#    #+#             */
/*   Updated: 2021/11/13 01:15:01 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*ncur;
	t_list	*new_lst;

	new_lst = 0;
	while (lst)
	{
		ncur = ft_lstnew(f(lst->content));
		if (ncur == 0)
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		else
			ft_lstadd_back(&new_lst, ncur);
		lst = lst->next;
	}
	return (new_lst);
}
