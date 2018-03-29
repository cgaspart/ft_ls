/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:46:32 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/12 15:46:34 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	l_option(char *dirname, char **order)
{
	ft_getdata(order, dirname);
}

static int	upper_r_checker(char *this, char *dirname, t_buffer *path)
{
	ft_putstr_b(path, dirname);
	if (!ft_issame(path->buffer, "/"))
		ft_addstr_b(path, "/");
	ft_addstr_b(path, this);
	if (ft_type(path->buffer) == 'd' && !ft_issame(this, ".") &&
	!ft_issame(this, "..") && ft_error(path->buffer, 1))
	{
		ft_putchar('\n');
		ft_putstr(path->buffer);
		ft_putstr(":\n");
		return (1);
	}
	else
		rm_lastpath_b(path);
	return (0);
}

static void	upper_r_option(t_opt *option, char *dirname, t_buffer *path)
{
	char		**order;
	int			i;

	i = 0;
	order = ft_get_order(dirname, option);
	if (option->l)
		ft_getdata(order, dirname);
	else
		ft_puttab(order);
	while (order[i])
	{
		if (upper_r_checker(order[i], dirname, path))
		{
			upper_r_option(option, path->buffer, path);
			rm_lastpath_b(path);
		}
		i++;
	}
	ft_free_tab(order);
	return ;
}

void		ft_f_simple(t_opt *option, char *dirname)
{
	char		**order;
	t_buffer	*path;

	if (!ft_is_file(dirname))
	{
		if (ft_error(dirname, 0))
		{
			order = ft_get_order(dirname, option);
			if (option->upper_r)
			{
				upper_r_option(option, dirname, path = ft_newbuffer());
				free(path);
			}
			else if (option->l == 1)
				l_option(dirname, order);
			else if (option->a || option->r || option->t)
				ft_puttab(order);
			ft_free_tab(order);
		}
	}
	else
	{
		ft_putstr(dirname);
		ft_putchar('\n');
	}
}
