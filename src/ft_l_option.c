/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:01:47 by cgaspart          #+#    #+#             */
/*   Updated: 2018/04/02 15:01:49 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_get_right(t_right *right, char *this, int i)
{
	if (i)
		ft_putchar('\n');
	ft_putchar(ft_type(this));
	ft_putright(right);
	free(right);
	if (ft_type(this) == 'l')
		return (1);
	return (0);
}

void			ft_get_blocks(t_data *data)
{
	ft_putstr("total ");
	ft_putnbr(data->blocks);
	ft_putchar('\n');
}

int				owner_grp_check(struct passwd *duser, struct group *dgroup,
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

void			is_link(char *name, t_buffer *this)
{
	char	buf[255];
	int		cc;

	cc = readlink(name, buf, BUFSIZ);
	buf[cc] = '\0';
	ft_rm_b_path(this);
	ft_addstr_b(this, " -> ");
	ft_addstr_b(this, buf);
}
