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

static char		*get_name(char *this, int isfile)
{
	char	*res;
	int 	len;
	int 	i;

	len = ft_strlen(this);
	i = 0;
	if (isfile)
		return (this);
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
		free(this);
		return (res);
	}
	return (this);
}

char			*islink(char *name, char *this)
{
	char buf[255];
	int cc;

	cc = readlink(this, buf, BUFSIZ);
	buf[cc] = '\0';
	name = ft_strjoin(name, " -> ");
	name = ft_strjoin(name, buf);
	return (name);
}

static void		ft_getstat(char *this, t_data **data, int isfile)
{
	struct stat			fstat;
	struct passwd		*duser;
	struct group		*dgroup;
	t_data				*tmp;

	if (lstat(this, &fstat) == -1)
	{
		perror("");
		exit(0);
	}
	tmp = (t_data*)malloc(sizeof(t_data));
	duser = getpwuid(fstat.st_uid);
	dgroup = getgrgid(fstat.st_gid);
	tmp->name = get_name(this, isfile);
	tmp->type = ft_type(this);
	if (tmp->type == 'l')
		tmp->name = islink(tmp->name, this);
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
	int				isfile;

	i = 0;
	isfile = 0;
	data = NULL;
	while (order[i])
	{
		if (dirname)
		{
			this = ft_strjoin("/", order[i]);
			this = ft_strjoin(dirname, this);
		}
		else
		{
			this = ft_strdup(order[i]);
			isfile = 1;
		}
		ft_getstat(this, &data, isfile);
		i++;
	}
	return (data);
}
