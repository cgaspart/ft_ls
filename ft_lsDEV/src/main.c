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

static void		arg_checker(char **argdir, char **argfile)
{
	int error;

	error = 1;
	if (argdir[0] != NULL && !ft_strcmp(argdir[0], "error"))
		error = 0;
	if (argfile[0] == NULL && !error)
	{
		free(argfile);
		free(argdir);
		exit(0);
	}
}

static void		ft_flag(int argc, char **argv, t_opt *option)
{
	char	**argfile;
	char	**argdir;

	if (option->r == 1)
	{
		argfile = ft_f_arg_revascii_file(argc, argv);
		argdir = ft_f_arg_revascii_dir(argc, argv);
	}
	else
	{
		argdir = ft_f_arg_ascii_dir(argc, argv);
		argfile = ft_f_arg_ascii_file(argc, argv);
	}
	arg_checker(argdir, argfile);
	if (argdir[0] == NULL && argfile[0] == NULL)
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
	if (argc > 2)
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
