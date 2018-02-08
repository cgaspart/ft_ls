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

static void		ft_flag(int argc, char **argv, t_opt *option)
{
	if (argc > 2)
		ft_putstr("Not set yet...");
	else
	{
		ft_putstr("Not set yet...");
	}

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
