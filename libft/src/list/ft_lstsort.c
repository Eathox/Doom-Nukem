/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:08:43 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/20 13:30:28 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*join(t_list *head, t_list *half,
					t_bool (*f)(const t_list *, const t_list *))
{
	if (head == NULL)
		return (half);
	if (half == NULL)
		return (head);
	if (f(head, half))
	{
		half->next = join(head, half->next, f);
		return (half);
	}
	head->next = join(head->next, half, f);
	return (head);
}

void			ft_lstsort(t_list **head,
					t_bool (*f)(const t_list *, const t_list *))
{
	t_list	*half;
	t_list	*temp;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	temp = ft_lstindex(*head, (ft_lstlen(*head) - 1) / 2);
	half = temp->next;
	temp->next = NULL;
	ft_lstsort(head, f);
	ft_lstsort(&half, f);
	*head = join(*head, half, f);
}
