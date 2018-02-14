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

static void	l_option(t_opt *option, char *dirname)
{
	t_data 	*data;
	char	**order;

	if (option->r == 0)
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabrev_ascii(order);
		data = ft_getdata(order);
		ft_print_l(&data);
	}
	else
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabascii(order);
		data = ft_getdata(order);
		ft_print_l(&data);
	}
}

static void	a_option(t_opt *option, char *dirname)
{
	char	**order;

	if (option->r == 0)
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabascii(order);
		ft_puttab(order);
	}
	else
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabrev_ascii(order);
		ft_puttab(order);
	}
}

static void	upper_r_option(t_opt *option, char *dirname)
{
	char	**order;
	t_data	*data;
	char	*path;
	int		i;

	i = 0;
	if (option->r == 0)
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabascii(order);
		ft_puttab(order);
	}
	else
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabrev_ascii(order);
		ft_puttab(order);
	}
	if (option->l)
	{
		data = ft_getdata(order);
		ft_print_l(&data);
	}
	while (order[i])
	{
		path = ft_strdup(dirname);
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, order[i]);
		if (!ft_is_file(path))
		{
			ft_putchar('\n');
			ft_putstr(path);
			ft_putstr(":\n");
			upper_r_option(option, path);
			free(path);
		}
		i++;
	}
	return ;
}

void		ft_f_simple(t_opt *option, char *dirname)
{
	if (!ft_is_file(dirname))
	{
		if (ft_error(dirname))
		{
			if (option->upper_r)
				upper_r_option(option, dirname);
			else if (option->l == 1)
				l_option(option, dirname);
			else if (option->a || option->r)
				a_option(option, dirname);
		}
	}
	else
	{
		ft_putstr(dirname);
		ft_putchar('\n');
	}
}
