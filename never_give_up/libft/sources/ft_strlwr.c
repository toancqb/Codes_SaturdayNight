/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:47:50 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 12:47:51 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlwr(char *s)
{
	size_t i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			s[i] = ft_tolower(s[i]);
			i++;
		}
	}
	return (s);
}