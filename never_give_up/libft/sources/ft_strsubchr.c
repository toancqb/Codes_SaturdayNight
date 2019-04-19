/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:05:08 by qtran             #+#    #+#             */
/*   Updated: 2018/07/26 14:05:09 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubchr(const char *s, char c)
{
	char	*ptr;

	if (!(ptr = ft_strchrs(s, c)))
		return (NULL);
	return (ft_strsub(s, 0, ptr - s));
}
