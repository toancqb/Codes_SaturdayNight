/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:38:49 by qtran             #+#    #+#             */
/*   Updated: 2018/09/30 19:38:50 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strsplit_len(char **strsplit)
{
	size_t	size;

	size = 0;
	if (strsplit)
		while (*strsplit)
		{
			size++;
			strsplit++;
		}
	return (size);
}
