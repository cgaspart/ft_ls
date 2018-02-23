/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_arg_revascii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:32:33 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/12 15:32:35 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_f_arg_revascii_file(int argc, char **argv)
{
	char    **res;
	int     i;
	int     j;

	i = 0;
	j = ft_skip_flag(argc, argv);
	if (j == -1)
		return (NULL);
	res = malloc(sizeof(char*) * argc);
	while (j < argc)
	{
		if (ft_is_file(argv[j]))
		{
			res[i] = argv[j];
			i++;
		}
		j++;
	}
	res[i] = NULL;
	res = ft_tabrev_ascii(res);
	return (res);
}

char		**ft_f_arg_revascii_dir(int argc, char **argv)
{
	char    **res;
	int     i;
	int     j;

	i = 0;
	j = ft_skip_flag(argc, argv);
	if (j == - 1)
		return (NULL);
	res = malloc(sizeof(char*) * argc);
	while (j < argc)
	{
		if (!ft_is_file(argv[j]) && ft_error(argv[j]))
		{
			res[i] = argv[j];
			i++;
		}
		j++;
	}
	res[i] = NULL;
	res = ft_tabrev_ascii(res);
	return (res);
}
