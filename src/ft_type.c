/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:17:24 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/29 08:35:16 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_type(char *dirname)
{
	struct stat fstat;

	if (stat(dirname, &fstat) == -1)
		return (0);
	if (S_ISDIR (fstat.st_mode))
		return ('d');
	if (S_ISREG (fstat.st_mode))
		return ('-');
	if (S_ISSOCK (fstat.st_mode))
		return ('s');
	if (S_ISFIFO (fstat.st_mode))
		return ('p');
	if (S_ISCHR (fstat.st_mode))
		return ('c');
	if (S_ISBLK (fstat.st_mode))
		return ('b');
	return (0);
}
