/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:22:36 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/31 12:06:46 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_get_right(t_right *right, char *this, int i)
{
	if (i)
		ft_putchar('\n');
	ft_putchar(ft_type(this));
	ft_putright(right);
	if (ft_type(this) == 'l')
		return (1);
	return (0);
}

static void		ft_get_blocks(t_data *data)
{
	ft_putstr("total ");
	ft_putnbr(data->blocks);
	ft_putchar('\n');
}

static int		owner_grp_check(struct passwd *duser, struct group *dgroup,
	t_data *data)
{
	if (duser == NULL || dgroup == NULL)
	{
		ft_putchar(' ');
		return (0);
	}
	ft_putchar(' ');
	ft_putstr(duser->pw_name);
	ft_print_space(data->ownerlen + 2, ft_strlen(duser->pw_name));
	ft_putstr(dgroup->gr_name);
	ft_print_space(data->grplen + 2, ft_strlen(dgroup->gr_name));
	return (1);
}

static char		*is_link(char *name, char *this)
{
	char buf[255];
	int cc;

	cc = readlink(this, buf, BUFSIZ);
	buf[cc] = '\0';
	name = ft_strjoin(name, " -> ");
	name = ft_strjoin(name, buf);
	return (name);
}

void			ft_print_l(t_data *data, int total, char **order)
{
	struct stat			fstat;
	struct passwd		*duser;
	struct group		*dgroup;
	int					i;
	char				*name;

	i = 0;
	if (total)
		ft_get_blocks(data);
	while (order[i])
	{
		if (lstat(order[i], &fstat) == -1)
		{
			perror("");
			exit(0);
		}
		name = ft_strdup(order[i]);
		duser = getpwuid(fstat.st_uid);
		dgroup = getgrgid(fstat.st_gid);
		if (ft_get_right(ft_right(fstat), order[i], i))
			name = is_link(order[i], name);
		ft_print_space(data->link + 2, ft_intlen(fstat.st_nlink));
		ft_putnbr(fstat.st_nlink);
		if (!owner_grp_check(duser, dgroup, data))
		{
			ft_putstr(ft_itoa(fstat.st_uid));
			ft_print_space(data->ownerlen + 2, ft_intlen(fstat.st_uid));
			ft_putstr(ft_itoa(fstat.st_gid));
			ft_print_space(data->grplen + 2, ft_intlen(fstat.st_gid));
		}
		if (ft_type(order[i]) == 'c' || ft_type(order[i]) == 'b')
		{
			ft_putnbr(major(fstat.st_rdev));
			ft_putchar(',');
			ft_print_space(4, ft_intlen(minor(fstat.st_rdev)));
			ft_putnbr(minor(fstat.st_rdev));
		}
		else
		{
			ft_print_space(data->size, ft_intlen(fstat.st_size));
			ft_putnbr(fstat.st_size);
		}
		ft_putchar(' ');
		ft_putstr(ft_date_converter(ctime(&fstat.st_mtime)));
		ft_putchar(' ');
		if (total)
			ft_putstr(ft_rm_str_path(name));
		else
			ft_putstr(name);
		i++;
	}
	free(data);
	ft_rm_tab_path(order);
	ft_putchar('\n');
}
