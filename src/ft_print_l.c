/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:22:36 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/30 08:30:36 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_right(t_data *data)
{
	ft_putchar('\n');
	ft_putchar(ft_type(data->name));
	ft_putright(data->right);
	ft_print_space(3, data->link);
}

void			ft_print_l(t_data **data)
{
	t_data		*ptrdata;

	ptrdata = *data;
	while (ptrdata)
	{
		ft_get_right(ptrdata);
		ft_putnbr(ptrdata->link);
		ft_putchar(' ');
		ft_putstr(ptrdata->owner);
		ft_putchar(' ');
		ft_putstr(ptrdata->grp);
		ft_print_space(6, ptrdata->size);
		ft_putnbr(ptrdata->size);
		ft_putchar(' ');
		ft_putstr(ptrdata->date);
		ft_putchar(' ');
		ft_putstr(ptrdata->name);
		ptrdata = ptrdata->next;
	}
}
