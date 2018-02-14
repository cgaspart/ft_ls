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

static void		ft_get_right(t_data *data, int i)
{
	if (i)
		ft_putchar('\n');
	ft_putchar(ft_type(data->name));
	ft_putright(data->right);
	ft_print_space(3, data->link);
}

static void		ft_get_blocks(t_data *data)
{
	int i;

	i = 0;
	while (data)
	{
		i = i + data->blocks;
		data = data->next;
	}
	ft_putstr("total ");
	ft_putnbr(i);
	ft_putchar('\n');
}

void			ft_print_l(t_data **data)
{
	int			i;
	t_data		*ptrdata;
	t_data		*blocksdata;

	ptrdata = *data;
	blocksdata = *data;
	i = 0;
	ft_get_blocks(blocksdata);
	while (ptrdata)
	{
		ft_get_right(ptrdata, i);
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
		i++;
	}
	ft_putchar('\n');
}
