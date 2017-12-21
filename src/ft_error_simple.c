/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:16:35 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/21 16:18:39 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_error_simple(char *dirname, int mod)
{
	DIR		*dir;

	dir = opendir(dirname);
	if (dir == NULL)
	{
		if (mod)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(dirname);
			ft_putstr(": ");
			perror("");
		}
		return (0);
	}
	closedir(dir);
	return (1);
}