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


#include "ft_ls.h"

static void	l_option(t_opt *option, char *dirname)
{
	t_data 	*data;
	char	**order;


	order = ft_get_lorder(dirname, option);
	data = ft_getdata(order, dirname);
	ft_print_l(&data);
}

static void	mod_option(t_opt *option, char *dirname)
{
	char	**order;

	order = ft_get_order(dirname, option);
	ft_puttab(order);
}

static void	upper_r_option(t_opt *option, char *dirname)
{
	char	**order;
	char	**lorder;
	t_data	*data;
	char	*path;
	int		i;

	i = 0;
	order = ft_get_order(dirname, option);
	if (option->l)
	{
		lorder = ft_get_lorder(dirname, option);
		data = ft_getdata(lorder, dirname);
		ft_print_l(&data);
	}
	else
		ft_puttab(order);
	while (order[i])
	{
		path = ft_strdup(dirname);
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, order[i]);
		if (!ft_is_file(path) && !ft_issame(order[i], ".") &&
		!ft_issame(order[i], ".."))
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
				mod_option(option, dirname);
		}
	}
	else
	{
		ft_putstr(dirname);
		ft_putchar('\n');
	}
}
