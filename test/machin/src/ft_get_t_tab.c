/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:19:41 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/28 11:19:43 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static time_t	get_time(char *this)
{
	struct stat		fstat;

	if (lstat(this, &fstat) == -1)
	{
		perror("");
		exit(0);
	}
	return (*(&fstat.st_mtime));
}

static char		**get_t_order(char **order)
{
	int		i;

	i = 0;
	while (order[i])
	{
		if (order[i + 1] && get_time(order[i]) < get_time(order[i + 1]))
		{
			ft_swap(&order[i], &order[i + 1]);
			i = 0;
		}
		else if (order[i + 1] && get_time(order[i]) == get_time(order[i + 1]))
		{
			if (ft_strcmp(order[i], order[i + 1]) > 0)
			{
				ft_swap(&order[i], &order[i + 1]);
				i = 0;
			}
			else
				i++;
		}
		else
			i++;
	}
	return (order);
}

static char		**get_t_revorder(char **order)
{
	int		i;

	i = 0;
	while (order[i])
	{
		if (order[i + 1] && get_time(order[i]) > get_time(order[i + 1]))
		{
			ft_swap(&order[i], &order[i + 1]);
			i = 0;
		}
		else if (order[i + 1] && get_time(order[i]) == get_time(order[i + 1]))
		{
			if (ft_strcmp(order[i], order[i + 1]) < 0)
			{
				ft_swap(&order[i], &order[i + 1]);
				i = 0;
			}
			else
				i++;
		}
		else
			i++;
	}
	return (order);
}

char			**ft_get_t_tab(char *dirname, char **order, int r_opt)
{
	order = ft_add_tab_path(order, dirname);
	if (r_opt == 0)
		order = get_t_order(order);
	else
		order = get_t_revorder(order);
	return (ft_rm_tab_path(order));
}
