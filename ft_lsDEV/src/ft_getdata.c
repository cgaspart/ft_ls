/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:12:49 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:13:02 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_getstat(char **order, t_data *data)
{
	struct stat			fstat;
	struct passwd		*duser;
	struct group		*dgroup;
	int					i;

	i = 0;
	while (order[i])
	{
		if (lstat(order[i], &fstat) == -1)
		{
			perror("");
			return (0);
		}
		duser = getpwuid(fstat.st_uid);
		dgroup = getgrgid(fstat.st_gid);
		if (ft_intlen(fstat.st_nlink) > data->link)
			data->link = ft_intlen(fstat.st_nlink);
		if (duser == NULL || dgroup == NULL)
		{
			if (ft_intlen(fstat.st_uid) > data->ownerlen)
				data->ownerlen = ft_intlen(fstat.st_uid);
			if (ft_intlen(fstat.st_gid) > data->grplen)
				data->grplen = ft_intlen(fstat.st_gid);
		}
		if (duser != NULL && (int)ft_strlen(duser->pw_name) > data->ownerlen)
			data->ownerlen = ft_strlen(duser->pw_name);
		if (dgroup != NULL && (int)ft_strlen(dgroup->gr_name) > data->grplen)
			data->grplen = ft_strlen(dgroup->gr_name);
		if (ft_intlen(fstat.st_size) > data->size)
			data->size = ft_intlen(fstat.st_size);
		data->blocks = data->blocks + fstat.st_blocks;
		i++;
	}
	return (1);
}

void			ft_getdata(char **order, char *dirname)
{
	t_data			*data;
	int				i;

	i = 0;
	data = malloc(sizeof(t_data));
	data->link = 0;
	data->ownerlen = 0;
	data->grplen = 0;
	data->size = 0;
	data->blocks = 0;
	if (dirname != NULL)
		order = ft_add_tab_path(order, dirname);
	if (ft_getstat(order, data))
		ft_print_l(data, !ft_is_file(dirname), order);
}
