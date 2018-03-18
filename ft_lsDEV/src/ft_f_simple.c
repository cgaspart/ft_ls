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

static void	mod_option(char **order)
{
	ft_puttab(order);
}

static char	*upper_r_checker(char *this, char *dirname)
{
	char	*path;

	path = ft_strdup(dirname);
	if (!ft_issame(path, "/"))
		path = ft_strjoin(path, "/");
	path = ft_strjoin(path, this);
	if (ft_type(path) == 'd' && !ft_issame(this, ".") &&
	!ft_issame(this, "..") && ft_error(path, 1))
	{
		ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
		return (path);
	}
	else
		return (NULL);
}

static void	upper_r_option(t_opt *option, char *dirname)
{
	char	**order;
	char	*path;
	int		i;

	i = 0;
	order = ft_get_order(dirname, option);
	if (option->l)
		ft_getdata(order, dirname);
	else
		ft_puttab(order);
	while (order[i])
	{
		path = upper_r_checker(order[i], dirname);
		if (path != NULL)
		{
			upper_r_option(option, path);
			free(path);
		}
		i++;
	}
	ft_free_tab(order);
	return ;
}

void		ft_f_simple(t_opt *option, char *dirname)
{
	char **order;

	if (!ft_is_file(dirname))
	{
		if (ft_error(dirname, 0))
		{
			order = ft_get_order(dirname, option);
			if (option->upper_r)
				upper_r_option(option, dirname);
			else if (option->l == 1)
				l_option(dirname, order);
			else if (option->a || option->r || option->t)
				mod_option(order);
			ft_free_tab(order);
		}
	}
	else
	{
		ft_putstr(dirname);
		ft_putchar('\n');
	}
}
