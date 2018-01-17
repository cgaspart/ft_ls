/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:17:24 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/05 09:05:26 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_type(char *dirname)
{
	struct stat fstat;

	if (stat(dirname, &fstat) == -1)
		return (NULL);
	if (S_ISDIR (fstat.st_mode))
		return ("DIR");
	if (S_ISREG (fstat.st_mode))
		return ("FILE");
	if (S_ISSOCK (fstat.st_mode))
		return ("SOCK");
	if (S_ISFIFO (fstat.st_mode))
		return ("FIFO");
	if (S_ISCHR (fstat.st_mode))
		return ("SCHAR");
	if (S_ISBLK (fstat.st_mode))
		return ("SBLOCK");
	return (NULL);
}
