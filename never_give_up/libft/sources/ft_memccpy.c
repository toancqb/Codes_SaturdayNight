/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:01:50 by qtran             #+#    #+#             */
/*   Updated: 2018/06/30 14:01:51 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	sym;
	unsigned char	*d;
	unsigned char	*s;

	sym = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == sym)
			return (d);
	}
	return (NULL);
}
