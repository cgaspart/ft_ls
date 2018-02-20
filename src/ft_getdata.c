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

static void		my_lstadd(t_data **alst, t_data *new)
{
	new->next = (*alst);
	(*alst) = new;
}

static char		*get_name(char *this)
{
	char	*res;
	int 	len;
	int 	i;

	len = ft_strlen(this);
	i = 0;
	if (ft_strchr(this, '/'))
	{
		while (this[len] != '/')
		{
			i++;
			len--;
		}
		res = malloc(sizeof(char) * i + 1);
		i = 0;
		len++;
		while (this[len + i] != '\0')
		{
			res[i] = this[len + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (this);
}

static void		ft_getstat(char *this, t_data **data)
{
	struct stat			fstat;
	struct passwd		*duser;
	struct group		*dgroup;
	t_data				*tmp;

	if (stat(this, &fstat) == -1)
	{
		perror("");
		exit(0);
	}
	tmp = (t_data*)malloc(sizeof(t_data));
	duser = getpwuid(fstat.st_uid);
	dgroup = getgrgid(fstat.st_gid);
	tmp->name = get_name(this);
	tmp->type = ft_type(this);
	tmp->right = ft_right(fstat);
	tmp->link = fstat.st_nlink;
	tmp->owner = ft_strdup(duser->pw_name);
	tmp->grp = ft_strdup(dgroup->gr_name);
	tmp->size = fstat.st_size;
	tmp->blocks = fstat.st_blocks;
	tmp->date = ft_date_converter(ctime(&fstat.st_mtime));
	my_lstadd(data, tmp);
}

t_data			*ft_getdata(char **order, char *dirname)
{
	t_data			*data;
	char			*this;
	int				i;

	i = 0;
	data = NULL;
	while (order[i])
	{
		this = ft_strjoin("/", order[i]);
		this = ft_strjoin(dirname, this);
		ft_getstat(this, &data);
		i++;
	}
	return (data);
}
