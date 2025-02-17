/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_lex_token.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:33:42 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:26 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

void	add_lex_token(t_token **tokens, t_token *new)
{
	static t_token	*last = NULL;

	if (last == NULL)
		*tokens = new;
	else
		last->next = new;
	last = new;
}
