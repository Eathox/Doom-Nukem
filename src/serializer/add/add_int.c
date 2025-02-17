/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_int.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:26:45 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:55:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void	add_int(int i, t_binary *bin)
{
	t_convert con;

	con.i = i;
	add_type(&bin->content, &bin->c_size, &con, sizeof(i));
}
