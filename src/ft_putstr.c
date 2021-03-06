/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:32:38 by okosiako          #+#    #+#             */
/*   Updated: 2016/12/04 10:51:59 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *s)
{
	int res;

	res = 0;
	if (s)
	{
		while (*s)
		{
			res += write(1, &(*s), 1);
			s++;
		}
	}
	return (res);
}
