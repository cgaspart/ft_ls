/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:43:50 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/29 10:37:17 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_conv2(char *res, char *time, int j)
{
	int i;

	i = 10;
	while (i < 16)
	{
		res[j] = time[i];
		i++;
		j++;
	}
	res[j] = '\0';
}

void			print_convert_date(char *time)
{
	char *buffer;

	buffer = ft_date_converter(time);
	ft_putchar(' ');
	ft_putstr(buffer);
	ft_putchar(' ');
	free(buffer);
}

char			*ft_date_converter(char *time)
{
	char	*res;
	int		i;
	int		j;

	i = 4;
	j = 0;
	res = malloc(sizeof(char) * 13);
	while (i < 10)
	{
		res[j] = time[i];
		j++;
		i++;
	}
	ft_conv2(res, time, j);
	return (res);
}
