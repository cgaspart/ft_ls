/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:32:29 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/21 09:32:30 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		l_file(char **argfile, t_opt *option)
{
	t_data *data;

	if (option->r)
		argfile = ft_tabascii(argfile);
	else
		argfile = ft_tabrev_ascii(argfile);
	data = ft_getdata(argfile, NULL);
	ft_print_l(&data, 0);
}

static void		multi_dir(char **argdir, t_opt *option)
{
	int i;

	i = 0;
	while (argdir[i])
	{
		ft_putstr(argdir[i]);
		ft_putstr(":\n");
		ft_f_simple(option, argdir[i]);
		if (argdir[i + 1] != NULL)
			ft_putstr("\n");
		i++;
	}
}

void			ft_f_multi(char **argfile, char **argdir, t_opt *option)
{
	int i;

	i = 0;
	if (argfile[0] != NULL)
	{
		if (option->l)
			l_file(argfile, option);
		else
			ft_puttab(argfile);
	}
	if (argdir[0] != NULL)
	{
		if (argfile[0])
			ft_putstr("\n");
		multi_dir(argdir, option);
	}
}
