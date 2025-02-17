/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wrddcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:26:33 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:39:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_char.h"

size_t		ft_wrddcount(const char *str, const char *dlm)
{
	t_uint64	bytes[2];
	size_t		count;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	count = 0;
	ft_chrsetbytes(bytes, dlm);
	while (str[i] != '\0')
	{
		if (ft_chrinbytes(bytes, str[i]))
			j = 0;
		else if (j == 0)
		{
			count++;
			j = 1;
		}
		i++;
	}
	return (count);
}
