/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nf_arg_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:27:37 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/07 21:27:39 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_nf_arg_ascii_file(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	res = malloc(sizeof(char*) * argc);
	while (j < argc)
	{
		if (ft_is_file(argv[j]) && ft_error(argv[j], 0))
		{
			res[i] = argv[j];
			i++;
		}
		j++;
	}
	res[i] = NULL;
	if (res[0] != NULL)
		res = ft_tabascii(res);
	return (res);
}

char		**ft_nf_arg_ascii_dir(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	res = malloc(sizeof(char*) * argc);
	while (j < argc)
	{
		if (!ft_is_file(argv[j]) && ft_error(argv[j], 0))
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
