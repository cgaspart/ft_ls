/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:54:29 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/12 13:18:17 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int		ft_rowner(struct stat fstat)
{
	int		res;

	res = 0;
	if (fstat.st_mode & S_IRUSR)
		res = res + 4;
	if (fstat.st_mode & S_IWUSR)
		res = res + 2;
	if (fstat.st_mode & S_IXUSR)
		res = res + 1;
	return (res);
}

static	int		ft_rgroup(struct stat fstat)
{
	int		res;

	res = 0;
	if (fstat.st_mode & S_IRGRP)
		res = res + 4;
	if (fstat.st_mode & S_IWGRP)
		res = res + 2;
	if (fstat.st_mode & S_IXGRP)
		res = res + 1;
	return (res);
}

static	int		ft_rother(struct stat fstat)
{
	int		res;

	res = 0;
	if (fstat.st_mode & S_IROTH)
		res = res + 4;
	if (fstat.st_mode & S_IWOTH)
		res = res + 2;
	if (fstat.st_mode & S_IXOTH)
		res = res + 1;
	return (res);
}

t_right			*ft_right(struct stat fstat)
{
	t_right		*right;

	right = malloc(sizeof(t_right));
	right->owner = ft_rowner(fstat);
	right->group = ft_rgroup(fstat);
	right->other = ft_rother(fstat);
	return (right);
}
