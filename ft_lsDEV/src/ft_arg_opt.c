/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:19:16 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:07:22 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		usage(char opt)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(opt);
	ft_putstr("\nusage: ft_ls [-Rafglrtu] [file ...]\n");
	exit (1);
}

static void		checker(char opt)
{
	if (opt != 'l' && opt != 'R' && opt != 'a' && opt != 'r' && opt != 't' &&
	opt != 'u' && opt != 'f' && opt != 'g' && opt != '1')
		usage(opt);
}

static void		ft_get_opt(char *argv, t_opt *option)
{
	int i;

	i = 1;
	while (argv[i] != '\0')
	{
		if (argv[i] == 'l')
			option->l = 1;
		if (argv[i] == 'R')
			option->upper_r = 1;
		if (argv[i] == 'a')
			option->a = 1;
		if (argv[i] == 'r')
			option->r = 1;
		if (argv[i] == 't')
			option->t = 1;
		if (argv[i] == 'u')
			option->u = 1;
		if (argv[i] == 'f')
			option->f = 1;
		if (argv[i] == 'g')
			option->g = 1;
		checker(argv[i]);
		i++;
	}
}

int				ft_arg_opt(char **argv, int argc, t_opt *option)
{
	int	res;
	int	i;

	i = 1;
	res = 0;
	*option = (t_opt){0, 0, 0, 0, 0, 0, 0, 0};
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			ft_get_opt(argv[i], option);
			res = 1;
		}
		else
			break ;
		i++;
	}
	return (res);
}
