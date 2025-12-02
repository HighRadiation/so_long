/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:42:38 by boksuz            #+#    #+#             */
/*   Updated: 2025/12/02 22:20:31 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// satır sayısını buluyoruz
int	count_linex(char *filename)
{
	int		fd;
	char	*line;							// her satırı tutacak pointer
	int 	count;							// satır sayacı

	fd = open(filename, O_RDONLY);			// dosyayı sadece okuma modunda aç
	while ((line = get_next_line(fd)))		// dosya bitine kadar satır oku
	{
		count++;							// her satırda sayacı artır
		free(line);							// okunan satırı serbest bırak (memort leak olmasın)
	}
	close(fd);								// dosya kapat
	return (count);							// toplam satır sayısını döndür
}

// galiba haritayı okuyorum
char	**read_map(char *filename)
{
	int 	fd;
	char 	**map;							// 2D array (harita)
	char 	**line;							// tek satır
	int 	lines;
	int 	i;

	i = 0;
	lines = count_lines(filename); 			// kaç satır var bul
	map = malloc(sizeof(char *) * (lines + 1));		// lines + 1 pointer'lık yer ayır (+) NULL için
	fd = open(filename, O_RDONLY);					// dosyayı tekrar aç (count_lines kapattı)
	while ((line = get_next_line(fd)))				// satır satır oku
	{
		map[i] = line;								// her satırı map dizisine koy
		i++;
	}
	map[i] = NULL;									// son elemanı null yap dizi sonu işareti
	close(fd);										// dosyayı kapat
	free(map);										// haritayı döndür
	return (map);
}

// dikdörtgen mi??
int	check_rectangular(char **map)
{
	int len;
	int i;

	i = 1;
	len = ft_strlen(map[0]);	// ilk satırın uzunluğmu al
	while (map[i])
	{
		if (ft_strlen(map[i] != len))		// bu satırın uzunluğu ilk satırla aynı mı?
			return (0);						// değilse dikdörtgen değil, 0 döndür
		i++;
	}
	return (1);								// hepsi aynıysa 1 döndür (başarılı)
}

// dıvarları kontrol ediyoruz.
int	check_walls(char **map)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(map[0]);

	// üst ve alt duvar
	while (map[0][i] && map[0][i] == '1')
		i++;
	if (map[0][i])
		return (0);
	return (1);
}
