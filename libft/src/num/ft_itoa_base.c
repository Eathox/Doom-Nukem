/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:41:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

char	*ft_itoa_base(intmax_t value, int base)
{
	return (ft_itoa_cbase(value, base, TRUE));
}
