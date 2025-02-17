/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_type.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 14:48:46 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:55:10 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

void	add_type(unsigned char **bytes, t_uint64 *b_size, t_convert *val,
			t_uint64 v_size)
{
	unsigned char *n_bytes;

	n_bytes = ft_memalloc(*b_size + v_size);
	if (n_bytes == NULL)
		error_msg_errno("Failed to alloc n_bytes");
	ft_memcpy(n_bytes, *bytes, *b_size);
	ft_memcpy(n_bytes + *b_size, val, v_size);
	ft_memdel((void**)bytes);
	*bytes = n_bytes;
	*b_size += v_size;
}
