/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgishyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:46:40 by vgishyan          #+#    #+#             */
/*   Updated: 2021/06/03 23:46:44 by vgishyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

size_t		ft_strlcpy(char* dest, const char* sorc, size_t dstsize)
{
    int index;

    if (dstsize == 0 || dest == NULL || sorc == NULL)
	return 0;
    if (*dest == '\0' || *sorc == '\0')
	return 0;
    index = 0;
    while ((index < dstsize) && sorc[index])
    {
	dest[index] = sorc[index];
	++index;
    }
    return (index);
}
