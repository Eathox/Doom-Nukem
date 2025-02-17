/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_gui_children.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 11:26:25 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:13 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

void	del_gui_children(t_gui *ui)
{
	t_transform	*cur;
	t_transform	*next;

	cur = ui->children;
	while (cur != NULL)
	{
		next = cur->next;
		del_elem(&cur);
		cur = next;
	}
	ui->children = NULL;
}
