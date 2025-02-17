/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:57:43 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

/*
** return (((0x60 - c) < 0) && ((c - 0x7B) < 0));
*/

t_bool		ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}
