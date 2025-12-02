/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:20:57 by boksuz            #+#    #+#             */
/*   Updated: 2025/12/02 22:25:35 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_lines(char *filename)
{
	int 	fd;
	char 	*line;
	int 	count;

	count = 0;
	fd = open(filename, O_RDONLY);
	while (line = get_next_line(fd))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}
