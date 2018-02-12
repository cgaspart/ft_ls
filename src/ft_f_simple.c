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

void		ft_f_simple(t_opt *option)
{
	t_data 	*data;
	char	**order;

	if (option->l == 1)
	{
		if (option->r == 0)
		{
			order = ft_get_ascii_tab(".", option->a);
			order = ft_tabrev_ascii(order);
			data = ft_getdata(order);
			ft_print_l(&data);
		}
		else
		{
			order = ft_get_ascii_tab(".", option->a);
			order = ft_tabascii(order);
			data = ft_getdata(order);
			ft_print_l(&data);
		}
	}
}
