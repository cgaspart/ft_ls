/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:55:07 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/23 11:35:12 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void ft_argsimple(char *dirname, char *option)
{
	t_data	*data;

	option = NULL;
	data = ft_getdata(dirname, &data);
}

int		main(int argc, char **argv)
{
	char	*option;

	if (argc == 1)
		ft_simple(".");
	if (argc == 2 && !ft_argcheck(argv))
		ft_simple(argv[1]);
	if (argc == 2 && (option = ft_argcheck(argv)))
		ft_argsimple(".", option);
	return (1);
}
