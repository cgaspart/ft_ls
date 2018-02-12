/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_arg_ascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:16:10 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/12 12:16:12 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_skip_flag(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			i++;
		else
			break ;
	}
	return (i);
}

char		**ft_f_arg_ascii_file(int argc, char **argv)
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
	res = ft_tabascii(res);
	return (res);
}

char		**ft_f_arg_ascii_dir(int argc, char **argv)
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
	res = ft_tabascii(res);
	return (res);
}
