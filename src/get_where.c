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

char		**get_where_file(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = ft_skip_flag(argc, argv);
	if (j == -1)
		return (NULL);
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

char		**get_where_dir(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = ft_skip_flag(argc, argv);
	res = malloc(sizeof(char*) * get_nbr_arg_dir(argc, argv) + 1);
	while (j < argc)
	{
		if (argv[j][0] == '-' && argv[j][1] == '-')
			res[i] = ".";
		else if (!ft_is_file(argv[j]) && ft_error(argv[j], 0))
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
