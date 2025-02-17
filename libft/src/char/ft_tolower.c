/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:53:23 by pholster      #+#    #+#                 */
/*   Updated: 2019/07/23 14:28:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

char		ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
