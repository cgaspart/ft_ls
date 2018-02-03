/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:49:54 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:07:51 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_is_file(char *dirname)
{
	struct stat fstat;

	if (stat(dirname, &fstat) == -1)
		return (0);
	if (S_ISREG(fstat.st_mode))
		return (1);
	if (S_ISSOCK(fstat.st_mode))
		return (1);
	if (S_ISFIFO(fstat.st_mode))
		return (1);
	if (S_ISCHR(fstat.st_mode))
		return (1);
	if (S_ISBLK(fstat.st_mode))
		return (1);
	return (0);
}
