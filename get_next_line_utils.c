/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:53:34 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/25 10:53:34 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *fixedbuffer, t_parameters *table)
{
	size_t	len;

	len = 0;
	if (fixedbuffer == NULL)
		return (0);
	while (fixedbuffer[len])
	{
		if (table->eolpos == 0 && fixedbuffer[len] == '\n')
			table->eolpos = len;
		len++;
	}
	return (len);
}

size_t	ft_strchr(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	int		n;

	n = (count * size);
	buffer = (char *)malloc(sizeof(char) * (n));
	if (buffer)
		while (n > 0)
			((char *)buffer)[--n] = 0;
	return (buffer);
}

char	*ft_strjoin(char *fixedbuffer, char *buffer, t_parameters *table)
{
	size_t	slen1;
	size_t	slen2;
	char	*dst;
	size_t	i;
	size_t	j;

	slen1 = ft_strlen((char *)fixedbuffer, table);
	slen2 = table->bytesread;
	dst = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < slen1)
		dst[i] = fixedbuffer[i];
	j = -1;
	while (++j < slen2)
		dst[i + j] = buffer[j];
	dst[i + j] = '\0';
	table->lenstr = i + j;
	return (dst);
}
