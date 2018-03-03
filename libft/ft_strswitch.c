/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:00:43 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/03 17:00:44 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strswitch(char **str1, char **str2)
{
	char *buffer;

	buffer = ft_strdup(*str1);
	*str1 = ft_strdup(*str2);
	*str2 = ft_strdup(buffer);
	free(buffer);
}
