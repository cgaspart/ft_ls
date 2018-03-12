/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:58:25 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/08 00:58:28 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_error(char *dirname, int space)
{
	DIR		*dir;

	dir = opendir(dirname);
	if (dir == NULL && ft_is_file(dirname) == -1)
	{
		if (space)
			ft_putchar('\n');
		ft_putstr("ft_ls: ");
		ft_putstr(dirname);
		ft_putstr(": ");
		perror("");
		return (0);
	}
	if (dir != NULL)
		closedir(dir);
	return (1);
}
