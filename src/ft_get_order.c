/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:06:44 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/19 13:06:45 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_get_lorder(char *dirname, t_opt *option)
{
	char **order;

	if (option->r == 0)
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabrev_ascii(order);
	}
	else
	{
		order = ft_get_ascii_tab(dirname, option->a);
		order = ft_tabascii(order);
	}
	return (order);
}

char	**ft_get_order(char *dirname, t_opt *option)
{
	char **order;

	order = ft_get_ascii_tab(dirname, option->a);
	if (option->t)
		order = ft_get_t_tab(dirname, order, option->r);
	else if (option->r == 0 && option->t == 0)
		order = ft_tabascii(order);
	else
		order = ft_tabrev_ascii(order);
	return (order);
}
