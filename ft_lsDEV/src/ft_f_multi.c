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

static void		l_file(char **argfile)
{
	t_data			*data;

	data = malloc(sizeof(t_data));
	data->link = 0;
	data->ownerlen = 0;
	data->grplen = 0;
	data->size = 0;
	data->blocks = 0;
	if (ft_getstat(argfile, data))
		ft_print_l(data, 0, argfile);
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
			l_file(argfile);
		else
			ft_puttab(argfile);
	}
	if (argdir[0] != NULL && ft_strcmp(argdir[0], "error"))
	{
		if (argfile[0])
			ft_putstr("\n");
		multi_dir(argdir, option);
	}
}
