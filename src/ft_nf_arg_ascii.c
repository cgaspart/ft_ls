/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nf_arg_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:27:37 by cgaspart          #+#    #+#             */
/*   Updated: 2018/04/05 15:54:33 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_nbr_arg_dir(int argc, char **argv)
{
	int i;
	int j;

	i = ft_skip_flag(argc, argv);
	j = 0;
	while (i < argc)
	{
		if (!ft_is_file(argv[i]) && ft_error_np(argv[i]))
			j++;
		i++;
	}
	return (j);
}

static int	get_nbr_arg_file(int argc, char **argv)
{
	int i;
	int j;

	i = ft_skip_flag(argc, argv);
	j = 0;
	while (i < argc)
	{
		if (ft_is_file(argv[i]) && ft_error_np(argv[i]))
			j++;
		i++;
	}
	return (j);
}

char		**ft_nf_arg_ascii_file(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	res = malloc(sizeof(char*) * get_nbr_arg_file(argc, argv) + 1);
	while (j < argc)
	{
		if (ft_is_file(argv[j]) && ft_error(argv[j], 0))
		{
			res[i] = ft_strdup(argv[j]);
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
	res = malloc(sizeof(char*) * get_nbr_arg_dir(argc, argv) + 1);
	while (j < argc)
	{
		if (!ft_is_file(argv[j]) && ft_error(argv[j], 0))
		{
			res[i] = ft_strdup(argv[j]);
			i++;
		}
		j++;
	}
	res[i] = NULL;
	if (res[0] != NULL)
		res = ft_tabascii(res);
	return (res);
}
