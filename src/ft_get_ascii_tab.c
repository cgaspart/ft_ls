/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:09:12 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:09:18 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_nbr_tab(char *dirname, int a_option)
{
	int				i;
	DIR				*dir;
	struct dirent	*file;

	i = 0;
	dir = opendir(dirname);
	while ((file = readdir(dir)))
	{
		if (a_option)
			i++;
		else if (file->d_name[0] != '.')
			i++;
	}
	closedir(dir);
	return (i);
}

static char		**ft_tab_fname(char *dirname, int a_option)
{
	int				i;
	char			**res;
	DIR				*dir;
	struct dirent	*file;

	i = 0;
	res = malloc(sizeof(char*) * ft_nbr_tab(dirname, a_option) + 1);
	dir = opendir(dirname);
	while ((file = readdir(dir)))
	{
		if (a_option)
			res[i] = ft_strdup(file->d_name);

		else if (file->d_name[0] != '.')
			res[i] = ft_strdup(file->d_name);

		i++;
	}
	res[i] = NULL;
	closedir(dir);
	return (res);
}

char			**ft_get_ascii_tab(char *dirname, int a_option)
{
	char			**fname;

	fname = ft_tab_fname(dirname, a_option);
	fname = ft_tabascii(fname);
	return (fname);
}
