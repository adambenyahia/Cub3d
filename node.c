/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:22:09 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 03:39:39 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	add_node(t_token **list, char *str)
{
	t_token	*new;

	if (!str)
		return (0);
	new = malloc(sizeof(t_token));
	if (!new)
		return (1);
	new->token = str;
	new->next = NULL;
	new->previous = NULL;
	if (!*list)
		return (*list = new, (*list)->tail = new, 0);
	new->previous = (*list)->tail;
	(*list)->tail->next = new;
	(*list)->tail = new;
	return (0);
}

void	deref_token2(t_token **tokens, t_token *node)
{
	if (node->previous)
		node->previous->next = node->next;
	if (node->next)
		node->next->previous = node->previous;
	if (node == *tokens)
		*tokens = (*tokens)->next;
	free(node->token);
	free(node);
}
