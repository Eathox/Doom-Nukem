/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dim_y_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:25:38 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:00 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_dim_y_int(t_parse_info *parse_info, const char *y_int)
{
	const int	y = ft_atoi(y_int);

	parse_info->dim.y = y;
}

static void		set_dim_y_float(t_parse_info *parse_info, const char *y_float)
{
	const int	y = ft_atoi(y_float);

	parse_info->dim.y += (float)y / (ft_pow(10, ft_strlen(y_float)));
}

t_return_code	dim_y_int_state(t_parse_manager *manager)
{
	set_dim_y_int(manager->parse_info, manager->token->token);
	return (check_next(manager->token, PERIOD));
}

t_return_code	dim_y_period_state(t_parse_manager *manager)
{
	return (check_next(manager->token, NUM));
}

t_return_code	dim_y_float_state(t_parse_manager *manager)
{
	set_dim_y_float(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
