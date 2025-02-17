/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lsttonumarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:14:49 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:10:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

intmax_t		*ft_lsttonumarr(t_list *lst)
{
	t_list		*current;
	intmax_t	*arr;
	intmax_t	*n;
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_lstlen(lst);
	if (len == 0)
		return (NULL);
	arr = (intmax_t *)ft_memalloc(sizeof(intmax_t) * len);
	if (arr == NULL)
		return (NULL);
	current = lst;
	while (current != NULL)
	{
		n = (intmax_t *)current->content;
		arr[i] = *n;
		current = current->next;
		i++;
	}
	return (arr);
}
