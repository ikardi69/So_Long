/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:19:32 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/29 15:42:37 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	ft_memcpy(result, s, ft_strlen(s));
	result[ft_strlen(s)] = '\0';
	return (result);
}
