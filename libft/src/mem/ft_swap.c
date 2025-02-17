/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:17:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	ft_swap(void **a, void **b)
{
	void	*temp_a;

	temp_a = *a;
	*a = *b;
	*b = temp_a;
}
