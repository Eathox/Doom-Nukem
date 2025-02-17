/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mod_float.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:02:16 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:20 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float		mod_float(float f0, float max)
{
	while (f0 >= max)
		f0 -= max;
	return (f0);
}
