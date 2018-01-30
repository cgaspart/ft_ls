/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putright.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:27:31 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/12 13:52:17 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	ft_rconverter(int	nbr)
{
	if ((nbr - 4) >= 0)
	{
		nbr = nbr - 4;
		ft_putchar('r');
	}
	else
		ft_putchar('-');
	if ((nbr - 2) >= 0)
	{
		nbr = nbr - 2;
		ft_putchar('w');
	}
	else
		ft_putchar('-');
	if ((nbr - 1) >= 0)
	{
		nbr= nbr - 1;
		ft_putchar('x');
	}
	else
		ft_putchar('-');
}

void	ft_putright(t_right *right)
{
	ft_rconverter(right->owner);
	ft_rconverter(right->group);
	ft_rconverter(right->other);
}
