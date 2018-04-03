/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:55:07 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:28:21 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		arg_error(int argc, char **argv)
{
	int i;
	int error;

	i = ft_skip_flag(argc, argv);
	error = 0;
	while (i < argc)
	{
		if (!ft_error_np(argv[i]))
			error = 1;
		i++;
	}
	return (error);
}

static void		ft_flag(int argc, char **argv, t_opt *option)
{
	char	**argfile;
	char	**argdir;

	argdir = get_where_dir(argc, argv);
	argfile = get_where_file(argc, argv);
	if (option->r == 1)
	{
		argfile = ft_tabrev_ascii(argfile);
		argdir = ft_tabrev_ascii(argdir);
	}
	if (argdir[0] == NULL && argfile[0] == NULL && !arg_error(argc, argv))
		ft_f_simple(option, ".");
	else if (argfile[0] == NULL && argdir[1] == NULL &&
		ft_skip_flag(argc, argv) == argc - 1)
		ft_f_simple(option, argdir[0]);
	else
		ft_f_multi(argfile, argdir, option);
	ft_free_tab(argfile);
	ft_free_tab(argdir);
}

static void		ft_no_flag(int argc, char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == '-')
		ft_simple(".");
	else if (argc > 2)
		ft_nf_multi(argc, argv);
	else
		ft_simple(argv[1]);
}

int				main(int argc, char **argv)
{
	t_opt	option;

	if (argc == 1)
		ft_simple(".");
	if (argc > 1)
	{
		if (!ft_arg_opt(argv, argc, &option))
			ft_no_flag(argc, argv);
		else
			ft_flag(argc, argv, &option);
	}
	return (1);
}
