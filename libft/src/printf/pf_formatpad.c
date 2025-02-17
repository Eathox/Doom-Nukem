/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatpad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:27:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_char.h"
#include "ft_str.h"
#include "ft_num.h"

static size_t	addprefix(t_info *info, char *str, size_t n)
{
	if (n == 0)
		return (0);
	pf_addnstr(info, str, n);
	if (info->var_type == VOID && info->width <= info->precision)
		return (0);
	if (info->precision > info->width && ft_strequ(str, "0") == FALSE)
		return (0);
	return (n);
}

static void		addpad(t_info *info, intmax_t len, char c)
{
	intmax_t	i;

	i = 0;
	while (i < len)
	{
		pf_addtobuff(info, &c, 1);
		i++;
	}
}

static void		addzero(t_info *info, intmax_t len, intmax_t space, char *prfx)
{
	size_t	prelen;
	char	c;

	prelen = ft_strlen(prfx);
	c = (pf_iszeropad(info)) ? '0' : ' ';
	len = len - ft_max(0, space);
	if (info->var_type == VOID || info->is_zero == FALSE)
		len -= addprefix(info, prfx, prelen);
	else if (ft_strequ_nocase(prfx, "0x") == FALSE && info->type != 'o')
		len -= addprefix(info, prfx, prelen);
	if (len > 0 && (info->flag[2] == FALSE || c != ' '))
		addpad(info, len, c);
}

static char		*getprefix(t_info *info)
{
	if (info->is_negative)
		return ("-");
	if (info->flag[3] && pf_ispositiveint(info))
		return ("+");
	if (info->flag[4] && pf_ispositiveint(info))
		return (" ");
	if ((info->flag[0] && ft_chrin("xX", info->type))
		|| info->var_type == VOID)
		return ((info->type == 'X') ? "0X" : "0x");
	if (info->flag[0] && info->type == 'o' && info->is_zero == FALSE &&
		info->precision <= info->var_len)
		return ("0");
	return ("");
}

void			pf_formatpad(t_info *info)
{
	char		*prfx;
	size_t		prelen;
	intmax_t	len;
	intmax_t	space;

	prfx = getprefix(info);
	prelen = ft_strlen(prfx);
	info->padadded = info->added;
	if (info->precision > info->width && pf_isstr(info) == FALSE)
		len = ft_max(0, info->precision) - info->var_len;
	else
		len = ft_max(0, info->width) - info->var_len;
	space = ft_max(0, info->width) - ft_max(info->var_len, info->precision);
	if (info->var_type == VOID || info->is_zero == FALSE)
		space -= prelen;
	else if (ft_strequ_nocase(prfx, "0x") == FALSE && info->type != 'o')
		space -= prelen;
	if (info->flag[1] && (info->precision == -1 ||
		(info->precision == 0 && info->flag[0] == FALSE)))
		space = 0;
	if (space > 0 && info->flag[2] == FALSE)
		addpad(info, space, ' ');
	addzero(info, len, space, prfx);
	info->padadded = info->added - info->padadded;
}
