/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgishyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:50:31 by vgishyan          #+#    #+#             */
/*   Updated: 2021/06/03 23:50:45 by vgishyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

bool is_null(const char* ptr)
{
    return (ptr == NULL);
}


bool get_dynamic_memory(char** ptr, int size) //return (ptr == NULL);
{
    ptr[0] = (char*)malloc(size);
    return (ptr == NULL);
}

int		count_int_number(int number)
{
    int count; 

    count = 0;
    while (number) 
    {
	number /= 10;
	++count;
    }
    return (number);
}