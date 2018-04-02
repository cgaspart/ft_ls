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

void			print_uid(struct stat fstat, t_data *data)
{
	ft_putstr(ft_itoa(fstat.st_uid));
	ft_print_space(data->ownerlen + 2, ft_intlen(fstat.st_uid));
	ft_putstr(ft_itoa(fstat.st_gid));
	ft_print_space(data->grplen + 2, ft_intlen(fstat.st_gid));
}

void			print_maj_min(struct stat fstat)
{
	ft_putnbr(major(fstat.st_rdev));
	ft_putchar(',');
	ft_print_space(4, ft_intlen(minor(fstat.st_rdev)));
	ft_putnbr(minor(fstat.st_rdev));
}

void			print_all(t_data *data, struct stat fstat, char *name,
t_buffer *buff)
{
	struct passwd		*duser;
	struct group		*dgroup;

	duser = getpwuid(fstat.st_uid);
	dgroup = getgrgid(fstat.st_gid);
	ft_print_space(data->link + 2, ft_intlen(fstat.st_nlink));
	ft_putnbr(fstat.st_nlink);
	if (!owner_grp_check(duser, dgroup, data))
		print_uid(fstat, data);
	if (ft_type(name) == 'c' || ft_type(name) == 'b')
		print_maj_min(fstat);
	else
	{
		ft_print_space(data->size, ft_intlen(fstat.st_size));
		ft_putnbr(fstat.st_size);
	}
	print_convert_date(ctime(&fstat.st_mtime));
	ft_putstr(buff->buffer);
}

void			ft_print_l(t_data *data, int total, char **order)
{
	struct stat			fstat;
	int					i;
	t_buffer			*name;

	i = 0;
	if (total)
		ft_get_blocks(data);
	name = ft_newbuffer();
	while (order[i])
	{
		if (lstat(order[i], &fstat) == -1)
		{
			perror("");
			exit(0);
		}
		ft_putstr_b(name, order[i]);
		if (ft_get_right(ft_right(fstat), order[i], i))
			is_link(order[i], name);
		else
			ft_rm_b_path(name);
		print_all(data, fstat, order[i], name);
		i++;
	}
	free(name);
	ft_putchar('\n');
}
