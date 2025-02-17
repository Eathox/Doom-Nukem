/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_gui_config.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:01:33 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:13 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <limits.h>

#include "libft/ft_str.h"

#include "game.h"
#include "lex.h"
#include "error.h"

int	open_gui_config(const char *file_name, char const *exec_path)
{
	int		fd;
	char	full_path[PATH_MAX];

	ft_strcpy(full_path, exec_path);
	ft_strcat(full_path, UI_CONFIG_PATH);
	ft_strcat(full_path, file_name);
	ft_strcat(full_path, ".ui.yml");
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		error_msg_errno(ft_strformat("Failed to open %s", full_path));
	return (fd);
}
