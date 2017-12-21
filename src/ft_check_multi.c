/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:02:28 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/21 16:18:36 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_valid(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_error_simple(argv[i], 1))
			j++;
		i++;
	}
	return (j);
}

char			**ft_check_multi(int argc, char **argv)
{
	int		i;
	int		j;
	char	**res;

	i = 1;
	j = 0;
	res = malloc(sizeof(char*) * ft_valid(argc, argv) + 1);
	while (i < argc)
	{
		if (ft_error_simple(argv[i], 0))
		{
			res[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	res = ft_tabascii(res);
	return (res);
}
