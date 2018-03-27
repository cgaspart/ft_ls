/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 00:25:50 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/23 00:25:52 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_buff(t_buffer *my_buffer, char *str)
{
	int i;

	i = 0;
	whiel (str[i] != '\0' && i < 4999)
	{
		my_buffer->buffer[i] = str[i];
		i++;
	}
	if (i == 4999)
		return (0);
	my_buffer->buffer[i] = '\0';
	return (1);
}

t_buffer	*ft_newbuffer(void)
{
	t_buffer *struct_buff;

	struct_buff = (t_buffer*)malloc(sizeof(t_buffer));
	return (struct_buff);
}
