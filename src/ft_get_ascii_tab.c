/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:09:12 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/30 10:01:04 by cgaspart         ###   ########.fr       */
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

char		  **ft_get_ascii_tab(char *dirname)
{
	char			**fname;
	DIR				*dir;

	dir = opendir(dirname);
	fname = ft_tabascii(ft_tab_fname(dirname));
	closedir(dir);
    return (fname);
}
