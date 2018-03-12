/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nf_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:22:33 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/08 00:33:35 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_nf_multi(int argc, char **argv)
{
	char	**argfile;
	char	**argdir;
	int		i;

	i = 0;
	argdir = ft_nf_arg_ascii_dir(argc, argv);
	argfile = ft_nf_arg_ascii_file(argc, argv);
	if (argfile[0])
		ft_puttab(argfile);
	if (argdir[0])
	{
		if (argfile[0])
			ft_putstr("\n");
		while (argdir[i])
		{
			ft_putstr(argdir[i]);
			ft_putstr(":\n");
			ft_simple(argdir[i]);
			if (argdir[i + 1] != NULL)
				ft_putstr("\n");
			i++;
		}
	}
}
