/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:24:05 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 00:42:10 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		free(tokens->token);
		tmp = tokens->next;
		free(tokens);
		tokens = tmp;
	}
}

int	parcer3(t_key key, t_args *args)
{
	if (!ft_strncmp(key.key, "NO", sizeof("NO")) && !args->texture.no)
		return (args->texture.no = ft_strdup(key.value), 1);
	else if (!ft_strncmp(key.key, "SO", sizeof("SO")) && !args->texture.so)
		return (args->texture.so = ft_strdup(key.value), 1);
	else if (!ft_strncmp(key.key, "WE", sizeof("WE")) && !args->texture.we)
		return (args->texture.we = ft_strdup(key.value), 1);
	else if (!ft_strncmp(key.key, "EA", sizeof("EA")) && !args->texture.ea)
		return (args->texture.ea = ft_strdup(key.value), 1);
	else if (!ft_strncmp(key.key, "F", sizeof("F")) && args->texture.f == -1)
		return (args->texture.f = rgbstringtoint(key.value), 1);
	else if (!ft_strncmp(key.key, "C", sizeof("C")) && args->texture.c == -1)
		return (args->texture.c = rgbstringtoint(key.value), 1);
	return (0);
}

int	parcer2(t_token **tokens, t_args *args)
{
	t_token	*tmp;
	t_key	key;

	tmp = *tokens;
	while (tmp)
	{
		if (!key_value(tmp->token, &key.key, &key.value))
		{
			if (!parcer3(key, args))
				return (list_to_map(tmp, args));
		}
		deref_token2(tokens, tmp);
		tmp = tmp->next;
	}
	return (0);
}
