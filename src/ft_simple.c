/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:03:45 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/17 14:31:15 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_nbr_tab(char *dirname)
{
	int				i;
	DIR				*dir;
	struct dirent	*file;

	i = 0;
	dir = opendir(dirname);
	while ((file = readdir(dir)))
	{
		if (file->d_name[0] != '.')
			i++;
	}
	closedir(dir);
	return (i);
}

static char		**ft_tab_fname(char *dirname)
{
	int				i;
	char			**res;
	DIR				*dir;
	struct dirent	*file;

	i = 0;
	res = malloc(sizeof(char*) * ft_nbr_tab(dirname) + 1);
	dir = opendir(dirname);
	while ((file = readdir(dir)))
	{
		if (file->d_name[0] != '.')
		{
			res[i] = ft_strdup(file->d_name);
			i++;
		}
	}
	res[i] = NULL;
	closedir(dir);
	return (res);
}

void			ft_simple(char	*dirname)
{
	char			**fname;
	DIR				*dir;

	if (!ft_is_file(dirname))
	{
		dir = opendir(dirname);
		fname = ft_tab_fname(dirname);
		ft_puttab(ft_tabascii(fname));
		closedir(dir);
	}
}
