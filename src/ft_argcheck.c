/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:19:16 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/19 17:32:17 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_strascii(char *str)
{
	int		i;
	char	buff;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < str[i + 1]) && (str[i + 1] != '\0'))
		{
			buff = str[i];
			str[i] = str[i + 1];
			str[i + 1] = buff;
			i = 0;
		}
		i++;
	}
	return (str);
}

char		*ft_argcheck(char **argv)
{
	int		i;
	int		j;
	char	*res;

	i = 1;
	j = 0;
	if (argv[1][0] == '-')
	{
		res = ft_strascii(ft_strdup(argv[1] + 1));
		return (res);
	}
	else
		return (NULL);
}
