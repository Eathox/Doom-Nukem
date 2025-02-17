/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:15:03 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:41:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"

t_bool		ft_putdouble(long double value, size_t n)
{
	return (ft_putdouble_fd(value, n, 1));
}
